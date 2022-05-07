//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <cstdlib>
#include <string>
#include <wheels/memory/memory_view.hpp>
#include <wheels/result/result.hpp>

namespace wheels {

class IReader {
 public:
  virtual std::string Read() = 0;
  virtual ~IReader() = default;
};

}



