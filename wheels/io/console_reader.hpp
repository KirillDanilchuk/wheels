//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <wheels/io/reader.hpp>
#include <wheels/io/input.hpp>
#include <string>

namespace wheels {

class ConsoleReader : public IReader {
 public:
  std::string Read() override {
    std::string buffer;
    std::getline(std::cin, buffer);
    return buffer;
  }
};

}



