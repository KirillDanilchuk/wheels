//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 07/05/2022.
//

#pragma once

#include <string>
#include <wheels/test/test.hpp>

namespace wheels {

struct ITestFormatter {
  virtual std::string MakeMessage(ITestPtr test, std::string extra) = 0;
};

using ITestFormatterPtr = std::shared_ptr<ITestFormatter>;

}
