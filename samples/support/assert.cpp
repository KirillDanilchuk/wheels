//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/support/assert.hpp>
#include <wheels/io/io.hpp>

int main() {
  constexpr int SUPER_VALUE = 42;
  const auto value = wheels::Input<int>("Enter value:");
  WHEELS_ASSERT(value < SUPER_VALUE, "Too large value");
  return 0;
}