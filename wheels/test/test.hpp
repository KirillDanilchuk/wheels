//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/05/2022.
//

#pragma once

#include <string>
#include <vector>
#include <memory>

namespace wheels {

struct ITest {
  virtual void Run() = 0;
  virtual std::string Name() = 0;
  virtual std::string SuiteName() = 0;
  virtual ~ITest() = default;
};

using ITestPtr = std::shared_ptr<ITest>;
using TestList = std::vector<ITestPtr>;

TestList& GetAllTests();
void SetCurrentTest(ITestPtr test);
ITestPtr GetCurrentTest();
void RegisterTest(ITestPtr test);

}