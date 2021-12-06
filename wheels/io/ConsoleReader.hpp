//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <wheels/io/IReader.hpp>
#include <wheels/io/input.hpp>
#include <string>

namespace wheels {

class ConsoleReader : public IReader {
 public:
  std::string Read() override {
    return Input<std::string>();
  }
};

}



