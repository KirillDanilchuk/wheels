//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#pragma once

#include <wheels/io/io.hpp>

namespace wheels::io {

class PrinterWithDelimiter {
 public:
  explicit PrinterWithDelimiter(std::string left_border,
                                std::string delimiter,
                                std::string right_border)
      : left_border_{std::move(left_border)}
      , delimiter_{std::move(delimiter)}
      , right_border_{std::move(right_border)} {
    // pass
  }
  explicit PrinterWithDelimiter(std::string delimiter)
      : delimiter_{std::move(delimiter)} {
    // pass
  }

  template <typename... Args>
  void PrintAll(Args&&... args) {
    wheels::io::Print(left_border_);
    wheels::io::PrintWithDelimiter(delimiter_, std::forward<Args>(args)...);
    wheels::io::Print(right_border_);
    Reset();
  }

  template <typename... Args>
  void PrintLineAll(Args&&... args) {
    PrintAll(std::forward<Args>(args)...);
    wheels::io::FlushAndNewLine();
  }

  template <typename T>
  void Print(T&& value) {
    if (is_first_print_) {
      wheels::io::Print(left_border_);
      wheels::io::Print(value);
      is_first_print_ = false;
    } else {
      wheels::io::Print(delimiter_);
      wheels::io::Print(value);
    }
  }

  void End() {
    wheels::io::Print(right_border_);
    Reset();
  }

  void Reset() {
    is_first_print_ = true;
  }

 private:
  std::string left_border_;
  std::string delimiter_;
  std::string right_border_;
  bool is_first_print_{true};
};
}
