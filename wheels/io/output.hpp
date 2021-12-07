//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#pragma once

#include <iostream>

namespace wheels {

inline void FlushAndNewLine() {
  std::cout << std::endl;
}

template <typename... Args>
void Print(Args&& ... args) {
  // https://en.cppreference.com/w/cpp/language/fold
  (std::cout << ... << std::forward<Args>(args));
}

template <typename... Args>
void PrintLine(Args&& ... args) {
  Print(std::forward<Args>(args)...);
  FlushAndNewLine();
}

template <typename Delimiter, typename First, typename... Args>
void PrintWithDelimiter(Delimiter&& delimiter, First&& first, Args&& ... args) {
  std::cout << first;
  ((std::cout << std::forward<Delimiter>(delimiter)
              << std::forward<Args>(args)), ...);
}

template <typename Delimiter, typename First, typename... Args>
void PrintLineWithDelimiter(Delimiter&& delimiter,
                            First&& first,
                            Args&& ... args) {
  PrintWithDelimiter(std::forward<Delimiter>(delimiter),
                     std::forward<First>(first),
                     std::forward<Args>(args)...);
  FlushAndNewLine();
}

}
