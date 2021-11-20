//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/io/io.hpp>
#include <vector>

int main() {
  std::vector ints{1, 2, 3, 4, 5};
  wheels::io::PrinterWithDelimiter printer(/*left_border=*/"[ ",
      /*delimiter=*/" | ",
      /*right_border=*/" ]");
  for (auto&& value : ints) {
    printer.Print(value);
  }
  printer.End(); // print right_border
  // [ 1, 2, 3, 4, 5 ]
  return 0;
}
