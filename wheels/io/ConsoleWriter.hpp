//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <wheels/io/IWriter.hpp>
#include <wheels/io/output.hpp>

namespace wheels {
class ConsoleWriter : public IWriter {
 public:
  Result<size_t> Write(MemoryView view) override {
    Print(view.AsStringView());
    return {view.Size()};
  }
};

}



