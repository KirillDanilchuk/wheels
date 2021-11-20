//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/support/panic.hpp>
#include <iostream>

namespace wheels::support::detail {
void Panic(SourceLocation where, std::string_view error) {
  std::cerr << "Panicked at " << where << ": " << error << std::endl;
  std::abort();
}
}