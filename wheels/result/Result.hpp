//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <type_traits>
#include <exception>

namespace detail {

template <typename T>
class ValueStorage {
  using Storage = std::aligned_storage_t<sizeof(T), alignof(T)>;

 public:
  template <typename... Args>
  void Construct(Args&& ... args) {
    new(&storage_) T(std::forward<Args>(args)...);
  }

  void Destroy() {
    Ptr()->~T();
  }

  T* Ptr() {
    return reinterpret_cast<T*>(&storage_);
  }

  T& Ref() {
    return *Ptr();
  }

 private:
  Storage storage_;
};

}

template <typename T>
class Result {
 public:
  static_assert(!std::is_reference_v<T>, "Reference types aren't support");
  using ValueType = T;
  using ExceptionType = std::exception;

  template <typename... Args>
  Result(Args&&... args) {
    storage_.Construct(std::forward<Args>(args)...);
    is_construct_ = true;
  }

  Result() = default;


  bool HasValue() {
    return is_construct_;
  }

  T Value() {
    return storage_.Ref();
  }

  ~Result() {
    if (HasValue()) {
      storage_.Destroy();
    }
  }

 private:
  bool is_construct_{false};
  detail::ValueStorage<T> storage_;
};



