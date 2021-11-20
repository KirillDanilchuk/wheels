//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#pragma once

#include <iostream>
#include <wheels/io/output.hpp>

namespace wheels::io {

template <typename ReturnType>
ReturnType Input() {
  ReturnType result;
  std::cin >> result;
  return result;
}

template <typename ReturnType, typename... Args>
ReturnType Input(Args&& ... args) {
  Print(std::forward<Args>(args)...);
  return Input<ReturnType>();
}

}
