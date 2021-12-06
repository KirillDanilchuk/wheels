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
  Result<size_t> Read(MemoryView destination) override {
    auto buffer = Input<std::string>();
    size_t size = std::min(buffer.size(), destination.Size());
    for (size_t i = 0; i < size; ++i) {
      destination[i] = buffer[i];
    }
    return {size};
  }

  std::string Read() override {
    return Input<std::string>();
  }
};

}



