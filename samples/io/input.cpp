//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/io/io.hpp>

int main() {
  using namespace wheels;
  auto value = Input<int>("Enter value:");
  PrintLine("Value:", value);
  return 0;
}
