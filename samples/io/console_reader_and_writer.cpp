//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#include <wheels/io/ConsoleReader.hpp>
#include <wheels/io/ConsoleWriter.hpp>
#include <wheels/memory/MemoryViewOf.hpp>

int main() {
  std::string buffer(100, '\0');
  wheels::ConsoleReader reader;
  wheels::ConsoleWriter writer;
  auto result = reader.Read();
  std::cout << result << std::endl;
  std::cout << buffer << std::endl;
  auto result1 = writer.Write(MemoryViewOf(buffer));
  std::cout << std::endl << result1.Value() << std::endl;

}