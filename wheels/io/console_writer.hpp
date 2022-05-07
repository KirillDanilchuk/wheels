//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <wheels/io/writer.hpp>
#include <wheels/io/output.hpp>

namespace wheels {
class ConsoleWriter : public IWriter {
 public:
  Result<size_t> Write(const std::string& view) override {
    PrintLine(view);
    return view.size();
  }
};

}



