//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <wheels/memory/MemoryView.hpp>
#include <wheels/result/Result.hpp>


class IWriter {
 public:
  virtual Result<size_t> Write(MemoryView view) = 0;
  virtual ~IWriter() = default;
};



