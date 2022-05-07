//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#pragma once

#include <sstream>
#include <string>

namespace wheels {
class StringBuilder {
 public:
  template <typename T>
  StringBuilder& operator<<(const T& next) {
    out_ << next;
    return *this;
  }

  operator std::string() const {
    return String();
  }

  std::string String() const {
    return out_.str();
  }

 private:
  std::ostringstream out_;
};

}