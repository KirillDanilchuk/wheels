//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <cstdlib>
#include <string>
#include <wheels/memory/MemoryView.hpp>
#include <wheels/result/Result.hpp>

namespace wheels {

class IReader {
 public:
  virtual Result<size_t> Read(MemoryView destination) = 0;
  virtual std::string Read() = 0;
  virtual ~IReader() = default;
};

}



