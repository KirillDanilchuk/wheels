//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 25/04/2022.
//

#include <wheels/test/test.hpp>
#include <wheels/test/fail_handler.hpp>
#include <wheels/test/success_handler.hpp>
#include <wheels/support/singleton.hpp>

namespace {

ITestPtr current_test;

std::string GetTestFullPath(const ITestPtr& test) {
  return test->SuiteName() + "::" + test->Name();
}

std::string MakeSuccessMessage(const ITestPtr& test) {
  return GetTestFullPath(test);
}

ITestPtr CurrentTest() noexcept {
  return current_test;
}

struct AbortOnFailHandler : wheels::ITestFailHandler {
  void Fail(std::string_view message) override {
    std::cout << CurrentTest()->Name() << std::endl;
    std::cout << message << std::endl;
    std::abort();
  }
};

struct SuccessHandler : wheels::ITestSuccessHandler {
  void Success(std::string_view message) override {
    std::cout << message << std::endl;
  }
};

}

TestList& GetAllTests() {
  return *wheels::Singleton<TestList>();
}

void Fail(const char* file, int line) {
  const auto kErrorMessage = std::string(file) + " " + std::to_string(line);
  wheels::GetTestFailHandler()->Fail(kErrorMessage);
}

void AllTestPassed() {
  std::cout << "ALL TESTS PASSED" << std::endl;
}

void RegisterTest(ITestPtr test) {
  wheels::Singleton<TestList>()->push_back(std::move(test));
}

void SetCurrentTest(ITestPtr test) {
  current_test = std::move(test);
}

void RunTests(const TestList& tests) {
  wheels::SetTestSuccessHandler(std::make_shared<SuccessHandler>());
  wheels::SetTestFailHandler(std::make_shared<AbortOnFailHandler>());
  for (auto&& test : tests) {
    SetCurrentTest(test);
    test->Run();
    wheels::GetTestSuccessHandler()->Success(MakeSuccessMessage(test));
  }
}