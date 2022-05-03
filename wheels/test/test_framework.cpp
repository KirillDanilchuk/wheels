//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 25/04/2022.
//

#include "test_framework.hpp"
#include <wheels/test/fail_handler.hpp>
#include <wheels/test/success_handler.hpp>
#include <wheels/support/singleton.hpp>

namespace {

struct AbortOnFailHandler : wheels::ITestFailHandler {
  void Fail(wheels::ITestPtr test, std::string_view error) override {
    std::cout << wheels::GetCurrentTest()->Name() << std::endl;
    if (!error.empty()) {
      std::cout << error << std::endl;
    }
    std::abort();
  }
};

struct SuccessHandler : wheels::ITestSuccessHandler {
  void Success(wheels::ITestPtr test) override {
    std::cout << test->SuiteName() << ":" << test->Name() << std::endl;
  }
};

}

void Fail(const char* file, int line) {
  wheels::GetTestFailHandler()->Fail(wheels::GetCurrentTest(), /*error=*/"");
}

void AllTestPassed() {
  std::cout << "ALL TESTS PASSED" << std::endl;
}

void RunTests(const wheels::TestList& tests) {
  wheels::SetTestSuccessHandler(std::make_shared<SuccessHandler>());
  wheels::SetTestFailHandler(std::make_shared<AbortOnFailHandler>());
  for (auto&& test : tests) {
    wheels::SetCurrentTest(test);
    test->Run();
    wheels::GetTestSuccessHandler()->Success(test);
  }
}