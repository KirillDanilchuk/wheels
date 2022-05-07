//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 25/04/2022.
//

#pragma once
#include <string>
#include <memory>
#include <vector>
#include <iostream>

#include <wheels/test/test.hpp>

namespace detail {
  void ConfigurateTestFramework();
  void RunTests(const wheels::TestList& tests);
  void AllTestPassed();
  void Fail(const char* file, int line);
}

#define TEST_SUITE(suite)                 \
namespace test_suite_##suite {            \
  std::string GetCurrentSuiteName() {     \
    return #suite;                        \
  }                                       \
}                                         \
namespace test_suite_##suite

#define TEST(name)                                \
void TestRoutine##name();                         \
struct Test##name : public wheels::ITest {        \
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

#define RUN_ALL_TESTS()                 \
int main() {                            \
  detail::ConfigurateTestFramework();   \
  auto& tests = wheels::GetAllTests();  \
  detail::RunTests(tests);              \
  detail::AllTestPassed();              \
}                                       \
[[maybe_unused]] static int request_semicolon_global_value_dont_use_it

#define ASSERT_TRUE(condition) \
REQUEST_SEMICOLON(if (!(condition)) { detail::Fail(__FILE__, __LINE__); })

#define ASSERT_FALSE(condition) ASSERT_TRUE(!(condition))
#define ASSERT_EQ(lhs, rhs) ASSERT_TRUE((lhs) == (rhs))
#define ASSERT_NOT_EQ(lhs, rhs) ASSERT_TRUE((lhs) != (rhs))
#define ASSERT_LESS(lhs, rhs) ASSERT_TRUE((lhs) < (rhs))
#define ASSERT_LESS_OR_EQ(lhs, rhs) ASSERT_TRUE((lhs) <= (rhs))
#define ASSERT_GREAT(lhs, rhs) ASSERT_TRUE((lhs) > (rhs))
#define ASSERT_GREAT_OR_EQ(lhs, rhs) ASSERT_TRUE((lhs) >= (rhs))
