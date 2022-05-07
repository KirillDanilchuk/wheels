//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 25/04/2022.
//

#include "test_framework.hpp"
#include "test_formatter.hpp"
#include <wheels/test/fail_handler.hpp>
#include <wheels/test/success_handler.hpp>
#include <wheels/test/test_logger.hpp>

using namespace wheels;

namespace {

struct DefaultFormatter : ITestFormatter {
  std::string MakeMessage(ITestPtr test,
                         const std::string& message) override {
    std::string result;
    result += test->SuiteName() += "::";
    result += test->Name();
    if (!message.empty()) {
      result += " | " + message;
    }
    return result;
  }
};

struct SuccessFormatter : DefaultFormatter {
  std::string MakeMessage(ITestPtr test, const std::string& message) override {
    return "Success: " + DefaultFormatter::MakeMessage(test, message);
  }
};

struct ErrorFormatter : DefaultFormatter {
  std::string MakeMessage(ITestPtr test, const std::string& message) override {
    return "Error: " + DefaultFormatter::MakeMessage(test, message);
  }
};

struct ConsoleLogger : ITestLogger {
  void Log(const std::string& message) override {
    std::cout << message << std::endl;
  }
};

std::string GetErrorMessage(const wheels::ITestPtr& test,
                            const std::string& extra_message) {
  return GetErrorFormatter()->MakeMessage(test, extra_message);
}

void LogError(const std::string& message) {
  GetErrorLogger()->Log(message);
}

void StopProgram() {
  std::abort();
}

struct AbortOnFailHandler : wheels::ITestFailHandler {
  void Fail(wheels::ITestPtr test, const std::string& error) override {
    const auto message{GetErrorMessage(test, error)};
    LogError(message);
    StopProgram();
  }
};

struct SuccessHandler : wheels::ITestSuccessHandler {
  void Success(wheels::ITestPtr test) override {
    const auto message{wheels::GetSuccessFormatter()->MakeMessage(test, "")};
    wheels::GetSuccessLogger()->Log(message);
  }
};

}

void detail::Fail(const char* file, int line) {
  wheels::GetTestFailHandler()->Fail(wheels::GetCurrentTest(), /*error=*/"");
}

void detail::AllTestPassed() {
  std::cout << "ALL TESTS PASSED" << std::endl;
}

void detail::ConfigurateTestFramework() {
  wheels::SetTestSuccessHandler(std::make_shared<SuccessHandler>());
  wheels::SetTestSuccessFormatter(std::make_shared<SuccessFormatter>());
  wheels::SetTestSuccessLogger(std::make_shared<ConsoleLogger>());

  wheels::SetTestFailHandler(std::make_shared<AbortOnFailHandler>());
  wheels::SetTestErrorFormatter(std::make_shared<ErrorFormatter>());
  wheels::SetTestErrorLogger(std::make_shared<ConsoleLogger>());
}

void detail::RunTests(const wheels::TestList& tests) {
  for (auto&& test : tests) {
    wheels::SetCurrentTest(test);
    test->Run();
    wheels::GetTestSuccessHandler()->Success(test);
  }
}