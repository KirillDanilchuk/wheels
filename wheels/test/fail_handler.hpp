//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/05/2022.
//

#pragma once

#include <memory>
#include <string_view>

namespace wheels {

struct ITestFailHandler {
  virtual void Fail(std::string_view message) = 0;
  virtual ~ITestFailHandler() = default;
};

using FailHandlerPtr = std::shared_ptr<ITestFailHandler>;

void SetTestFailHandler(FailHandlerPtr fail_handler);
FailHandlerPtr GetTestFailHandler();

}