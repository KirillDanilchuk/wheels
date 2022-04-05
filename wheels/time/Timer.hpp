//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 05/04/2022.
//

#pragma once

#include <chrono>

namespace wheels {
class Timer {
 public:
  Timer()
      : begin_{std::chrono::steady_clock::now()} {

  }

  size_t Elapsed() {
    auto end = std::chrono::steady_clock::now();
    using std::chrono::duration_cast;
    return duration_cast<std::chrono::milliseconds>(end - begin_).count();
  }

 private:
  std::chrono::steady_clock::time_point begin_;
};

}
