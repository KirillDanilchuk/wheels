//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 07/05/2022.
//

#pragma once

#include <string>
#include <memory>

namespace wheels {

struct ITestLogger {
  virtual void Log(const std::string& message) = 0;
  virtual ~ITestLogger() = default;
};

using ITestLoggerPtr = std::shared_ptr<ITestLogger>;

void SetTestSuccessLogger(ITestLoggerPtr logger);
ITestLoggerPtr GetSuccessLogger();

void SetTestErrorLogger(ITestLoggerPtr logger);
ITestLoggerPtr GetErrorLogger();

}
