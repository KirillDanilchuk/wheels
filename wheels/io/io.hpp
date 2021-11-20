//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#pragma once

#include <iostream>

namespace wheels::io {

template <typename ReturnType, typename... Args>
ReturnType Input(Args&& ... args) {
  ReturnType result;
  std::cout << (args << ...);
  std::cin >> result;
  return result;
}

}
