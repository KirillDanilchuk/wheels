//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/05/2022.
//

#pragma once

#include <memory>
#include <string_view>
#include <wheels/test/test.hpp>

namespace wheels {

struct ITestSuccessHandler {
  virtual void Success(ITestPtr test) = 0;
  virtual ~ITestSuccessHandler() = default;
};

using SuccessHandlerPtr = std::shared_ptr<ITestSuccessHandler>;

void SetTestSuccessHandler(SuccessHandlerPtr success_handler);
SuccessHandlerPtr GetTestSuccessHandler();

}