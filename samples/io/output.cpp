//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/io/io.hpp>

int main() {
  wheels::io::PrintLine('a', 'b', 1, "number");
  wheels::io::PrintLineWithDelimiter(", ", 1, 2, 3);
  return 0;
}