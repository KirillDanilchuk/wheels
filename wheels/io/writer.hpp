//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <wheels/memory/memory_view.hpp>
#include <wheels/result/result.hpp>

namespace wheels {

class IWriter {
 public:
  virtual Result<size_t> Write(const std::string& view) = 0;
  virtual ~IWriter() = default;
};

}
