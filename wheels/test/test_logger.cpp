//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 07/05/2022.
//

#include <wheels/test/test_logger.hpp>

namespace wheels {

namespace {
  ITestLoggerPtr current_success_logger;
  ITestLoggerPtr current_error_logger;
}

void SetTestSuccessLogger(ITestLoggerPtr logger) {
  current_success_logger = std::move(logger);
}

ITestLoggerPtr GetSuccessLogger() {
  return current_success_logger;
}

void SetTestErrorLogger(ITestLoggerPtr logger) {
  current_error_logger = std::move(logger);
}

ITestLoggerPtr GetErrorLogger() {
  return current_error_logger;
}
}
