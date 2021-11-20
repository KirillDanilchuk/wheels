//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/io/io.hpp>

int main() {
  std::vector ints{1, 2, 3, 4, 5};
  wheels::PrinterWithDelimiter printer(/*left_border=*/"[ ",
      /*delimiter=*/" | ",
      /*right_border=*/" ]");
  for (auto&& value : ints) {
    printer.Print(value);
  }
  printer.End(); // print right_border

  wheels::FlushAndNewLine();

  wheels::PrinterWithDelimiter simple_printer(/*delimiter=*/", ");
  simple_printer.PrintLineAll("Begin", 42, "End");
  return 0;
}
