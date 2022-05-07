//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#include <wheels/io/console_reader.hpp>
#include <wheels/io/console_writer.hpp>
#include <wheels/memory/memory_view_of.hpp>

int main() {
  wheels::ConsoleReader reader;
  wheels::ConsoleWriter writer;
  auto result = reader.Read();
  std::cout << result << std::endl;
  auto result1 = writer.Write(result);
  std::cout << std::endl << result1.Value() << std::endl;

}