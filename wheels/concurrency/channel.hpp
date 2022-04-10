//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 09/04/2022.
//

#pragma once
#include <mutex>
#include <condition_variable>
#include <optional>
#include <thread>
#include <memory>
#include <deque>
#include <functional>

namespace wheels {
template <typename T>
class Channel;

template <typename T>
using ChannelPtr = std::shared_ptr<Channel<T>>;

template <typename T>
class Future {
  friend class Channel<T>;

 public:
  void CloseChannel() {
    channel_->Close();
  }

  std::optional<T> Get() {
    std::unique_lock lock{channel_->mutex_};
    while (channel_->queue_.empty() && !channel_->is_close_) {
      channel_->queue_not_empty_or_close_.wait(lock);
    }
    if (!channel_->queue_.empty()) {
      T result = std::move(channel_->queue_.back());
      channel_->queue_.pop_back();
      return result;
    } else {
      return std::nullopt;
    }
  }

 private:
  Future(ChannelPtr<T> channel)
      : channel_{std::move(channel)} {
    // pass
  }

 private:
  ChannelPtr<T> channel_;
};

template <typename T>
class Promise {
  friend class Channel<T>;

 public:
  void CloseChannel() {
    channel_->Close();
  }

  template <typename U>
  bool Put(U&& value) {
    std::unique_lock lock{channel_->mutex_};
    if (channel_->is_close_) {
      return false;
    }
    channel_->queue_.push_front(std::forward<U>(value));
    channel_->queue_not_empty_or_close_.notify_one();
    return true;
  }

 private:
  Promise(ChannelPtr<T> channel)
      : channel_{std::move(channel)} {
    // pass
  }

 private:
  ChannelPtr<T> channel_;
};

template <typename T>
class Channel : public std::enable_shared_from_this<Channel<T>> {
  friend class Future<T>;
  friend class Promise<T>;

 public:
  static ChannelPtr<T> Create() {
    return std::make_shared<Channel<T>>();
  }

  void Close() {
    std::lock_guard guard{mutex_};
    is_close_ = true;
    queue_not_empty_or_close_.notify_one();
  }

  Future<T> MakeFuture() {
    return Future<T>(this->shared_from_this());
  }

  Promise<T> MakePromise() {
    return Promise<T>(this->shared_from_this());
  }

 private:
  std::deque<T> queue_;
  bool is_close_{false};
  std::mutex mutex_;
  std::condition_variable queue_not_empty_or_close_;
};

struct Unit {};

template <typename T, typename Result>
Future<Result> ViaChannel(std::function<void(Promise<T>)> producer,
                          std::function<void(Future<T>,
                                             Promise<Result>)> consumer) {
  auto shared_channel = Channel<T>::Create();
  std::thread{producer, shared_channel->MakePromise()}.detach();

  auto result_channel = Channel<Result>::Create();
  std::thread{
      consumer, shared_channel->MakeFuture(),
      result_channel->MakePromise()
  }.detach();

  return result_channel->MakeFuture();
}
}
