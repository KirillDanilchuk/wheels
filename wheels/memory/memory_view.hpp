//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <cstdlib>
#include <string_view>
#include <wheels/support/assert.hpp>

class MemoryView {
 public:
  MemoryView(char* buffer, size_t size) noexcept
  : begin_{buffer}, size_{size} {
    // pass
  }

  char& operator[](size_t i) noexcept {
    WHEELS_ASSERT(i < Size(), "Out of bounds");
    return Begin()[i];
  }

  [[nodiscard]] char* Begin() noexcept {
    return begin_;
  }

  [[nodiscard]] char* End() noexcept {
    return begin_ + size_;
  }

  [[nodiscard]] char* Back() noexcept {
    WHEELS_ASSERT(NotEmpty(), "memory view is empty");
    return End() - 1;
  }

  [[nodiscard]] size_t Size() const noexcept {
    return size_;
  }

  [[nodiscard]] bool Empty() const noexcept {
    return size_;
  }

  [[nodiscard]] bool NotEmpty() const noexcept {
    return !Empty();
  }

  MemoryView& operator+=(size_t offset) noexcept {
    WHEELS_ASSERT(offset <= size_, "Out of bounds");
    begin_ += offset;
    size_ -= offset;
    return *this;
  }

  [[nodiscard]] std::string_view AsStringView() const noexcept {
    return {begin_, size_};
  }

 private:
  char* begin_;
  size_t size_;
};
