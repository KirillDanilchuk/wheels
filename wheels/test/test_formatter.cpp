//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 07/05/2022.
//

#include <wheels/test/test_formatter.hpp>

namespace wheels {

namespace {
  ITestFormatterPtr current_error_formatter;
  ITestFormatterPtr current_success_formatter;
}

void SetTestErrorFormatter(ITestFormatterPtr formatter) {
  current_error_formatter = std::move(formatter);
}

ITestFormatterPtr GetErrorFormatter() {
  return current_error_formatter;
}

void SetTestSuccessFormatter(ITestFormatterPtr formatter) {
  current_success_formatter = std::move(formatter);
}

ITestFormatterPtr GetSuccessFormatter() {
  return current_success_formatter;
}

}