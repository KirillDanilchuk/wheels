//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/12/2021.
//

#pragma once
#include <type_traits>
#include <utility>
#include <new>
#include <cstddef>

namespace wheels {

template <typename T, size_t kSize, size_t kAlignment>
class Pimpl {
 public:
  using ValueType = T;

  template <typename... Args>
  explicit Pimpl(Args&& ... args) {
    Validate<sizeof(T), alignof(T)>();
    new(Ptr()) T(std::forward<Args>(args)...);
  }

  Pimpl(Pimpl&& rhs) noexcept {
    new(Ptr()) T(std::move(*rhs));
  }

  Pimpl(const Pimpl& rhs) {
    new(Ptr()) T(*rhs);
  }

  Pimpl& operator=(const Pimpl& rhs)
      noexcept((*Ptr() = std::declval<ValueType>())) {
    *Ptr() = *rhs;
    return *this;
  }

  Pimpl& operator=(Pimpl&& rhs)
      noexcept((*Ptr() = std::move(std::declval<ValueType>()))) {
    *Ptr() = std::move(*rhs);
    return *this;
  }

  T* Ptr() {
    return reinterpret_cast<T*>(&storage_);
  }

  const T* Ptr() const {
    return reinterpret_cast<const T*>(&storage_);
  }

  T& operator*() {
    return *Ptr();
  }

  T* operator->() {
    return Ptr();
  }

  const T& operator*() const {
    return *Ptr();
  }

  const T* operator->() const {
    return Ptr();
  }

  ~Pimpl() {
    Ptr()->~T();
  }

 private:
  template <size_t kActualSize, size_t kActualAlign>
  void Validate() const {
    static_assert(kSize == kActualSize, "kSize and sizeof(T) mismatch");
    static_assert(kAlignment == kActualAlign,
                  "kAlignment and alignof(T) mismatch");
  }

 private:
  std::aligned_storage_t<kSize, kAlignment> storage_;
};

}
