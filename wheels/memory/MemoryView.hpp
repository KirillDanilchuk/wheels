//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <cstdlib>
#include <wheels/support/assert.hpp>

class MemoryView {
 public:
  MemoryView(char* buffer, size_t size) noexcept
  : begin_{buffer}, size_{size} {
    // pass
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

 private:
  char* begin_;
  size_t size_;
};
