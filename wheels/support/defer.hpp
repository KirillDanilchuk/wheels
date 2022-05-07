//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 08/05/2022.
//

#pragma once

#include <utility>
#include <wheels/concepts/callable.hpp>

namespace wheels {

// It's defer from Golang
// https://gobyexample.com/defer
template <Callable F>
class Defer {
 public:
  Defer(F function) : function_{std::move(function)} {
    // pass
  }

  ~Defer() {
    function_();
  }

 private:
  F function_;
};

}