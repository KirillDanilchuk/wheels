//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#pragma once

#include <string_view>
#include <iostream>
namespace wheels {

struct SourceLocation {
  std::string_view file_;
  std::string_view function_;
  int line_;

  static SourceLocation Current(std::string_view file = __builtin_FILE(),
                                std::string_view function = __builtin_FUNCTION(),
                                int line = __builtin_LINE()) {
    return {file, function, line};
  }

};

std::ostream& operator<<(std::ostream& out, const SourceLocation& where);
} // namespace wheels

#define WHEELS_HERE \
::wheels::SourceLocation{__FILE__, __PRETTY_FUNCTION__, __LINE__}