//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 25/04/2022.
//

#pragma once
#include <string>
#include <memory>
#include <vector>
#include <iostream>

struct ITest {
  virtual void Run() = 0;
  virtual std::string Name() = 0;
  virtual std::string SuiteName() = 0;
  virtual ~ITest() = default;
};

using ITestPtr = std::shared_ptr<ITest>;
using TestList = std::vector<ITestPtr>;

void RunTests(const TestList& tests);
void AllTestPassed();
void DispatchTest(const ITestPtr& test);
TestList& GetAllTests();
void SetCurrentTest(ITestPtr test);
void RegisterTest(ITestPtr test);
void Fail(const char* file, int line);

#define TEST_SUITE(suite)                 \
namespace test_suite_##suite {            \
  std::string GetCurrentSuiteName() {     \
    return #suite;                        \
  }                                       \
}                                         \
namespace test_suite_##suite

#define TEST(name)                                \
void TestRoutine##name();                         \
struct Test##name : public ITest {                \
  void Run() override {                           \
    TestRoutine##name();                          \
  }                                               \
                                                  \
  std::string Name() override {                   \
    return #name;                                 \
  }                                               \
                                                  \
  std::string SuiteName() override {              \
      return GetCurrentSuiteName();               \
  }                                               \
};                                                \
                                                  \
struct TestRegistrar##name {                      \
  TestRegistrar##name() noexcept {                \
    RegisterTest(std::make_shared<Test##name>()); \
  }                                               \
};                                                \
static TestRegistrar##name test_registrar_##name; \
                                                  \
void TestRoutine##name()

#define REQUEST_SEMICOLON(expression) do { expression } while(false)

#define RUN_ALL_TESTS()       \
int main() {                  \
  auto& tests = GetAllTests();\
  RunTests(tests);            \
  AllTestPassed();            \
}                             \
[[maybe_unused]] static int request_semicolon_global_value_dont_use_it

#define ASSERT_TRUE(condition) \
REQUEST_SEMICOLON(if (!(condition)) { Fail(__FILE__, __LINE__); })