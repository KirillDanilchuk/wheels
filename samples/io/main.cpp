//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/io/io.hpp>
#include <string>

int main() {
  using wheels::io::Input;
  auto i = Input<int>("Enter integer value:");
  auto str = Input<std::string>("Enter string:");
  std::cout << i << std::endl;
  std::cout << str << std::endl;
}
