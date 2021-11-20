//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/io/io.hpp>

int main() {
  auto value = wheels::io::Input<int>("Enter first value:");
  wheels::io::PrintLine(value);
  return 0;
}

