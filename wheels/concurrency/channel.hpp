//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 09/04/2022.
//

#pragma once
#include <mutex>
#include <condition_variable>
#include <optional>
#include <thread>
#include <memory>
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

  std::optional<T> GetOptional() {
    std::unique_lock lock{channel_->mutex_};
    while (!channel_->value_.has_value() && !channel_->is_close_) {
      channel_->value_ready_or_close_.wait(lock);
    }
    if (channel_->is_close_) {
      return std::nullopt;
    }
    T result = std::move(channel_->value_.value());
    channel_->value_ = std::nullopt;
    channel_->value_empty_or_close_.notify_one();
    return result;
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
    while (channel_->value_.has_value() && !channel_->is_close_) {
      channel_->value_empty_or_close_.wait(lock);
    }
    if (channel_->is_close_) {
      return false;
    }
    channel_->value_ = std::forward<U>(value);
    channel_->value_ready_or_close_.notify_one();
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
  void Close() {
    std::lock_guard guard{mutex_};
    is_close_ = true;
    value_empty_or_close_.notify_one();
    value_ready_or_close_.notify_one();
  }

  Future<T> MakeFuture() {
    return Future<T>(this->shared_from_this());
  }

  Promise<T> MakePromise() {
    return Promise<T>(this->shared_from_this());
  }

 private:
  std::optional<T> value_;
  bool is_close_{false};
  std::mutex mutex_;
  std::condition_variable value_ready_or_close_;
  std::condition_variable value_empty_or_close_;
};

struct Unit {};

template <typename T>
ChannelPtr<T> MakeChannel() {
  return std::make_shared<Channel<T>>();
}

template <typename T, typename Result>
Future<Result> ViaChannel(std::function<void(Promise<T>)> producer,
                          std::function<void(Future<T>,
                                             Promise<Result>)> consumer) {
  auto shared_channel = MakeChannel<T>();
  std::thread{producer, shared_channel->MakePromise()}.detach();

  auto result_channel = MakeChannel<Result>();
  std::thread{
      consumer, shared_channel->MakeFuture(),
      result_channel->MakePromise()
  }.detach();

  return result_channel->MakeFuture();
}
}
