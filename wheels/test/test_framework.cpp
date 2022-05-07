//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 25/04/2022.
//

#include <wheels/test/test_framework.hpp>
#include <wheels/test/test_formatter.hpp>
#include <wheels/test/fail_handler.hpp>
#include <wheels/test/success_handler.hpp>
#include <wheels/test/test_logger.hpp>
#include <wheels/io/io.hpp>
#include <wheels/random/random.hpp>
#include <wheels/time/Timer.hpp>
#include <vector>

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
    auto suffix{WHEELS_GREEN("PASSED: ")};
    return suffix + DefaultFormatter::MakeMessage(test, message);
  }
};

struct ErrorFormatter : DefaultFormatter {
  std::string MakeMessage(ITestPtr test, const std::string& message) override {
    auto suffix{WHEELS_RED("ERROR: ")};
    return suffix + DefaultFormatter::MakeMessage(test, message);
  }
};

struct ConsoleLogger : ITestLogger {
  void Log(const std::string& message) override {
    wheels::PrintLine(message);
  }
};

std::string GetErrorMessage(const wheels::ITestPtr& test,
                            const std::string& extra_message) {
  return GetErrorFormatter()->MakeMessage(test, extra_message);
}

void LogError(const std::string& message) {
  GetErrorLogger()->Log(message);
}

std::string ChoseAngrySmile() {
  static const std::vector<std::string> smileys{
      "( ▀ 益 ▀ )", "ヾ( ･`⌓´･)ﾉﾞ", "ヽ(｀○´)/", "ヾ(*｀⌒´*)ﾉ", "╰༼=ಠਊಠ=༽╯",
      "ι(｀ロ´)ノ", "(･｀ｪ´･)つ", "ヾ(｀⌒´メ)ノ″", "ヽ༼ ಠ益ಠ ༽ﾉ"
  };
  return wheels::GetRandomValue(smileys);
}

void LogAngrySmile() {
  GetErrorLogger()->Log(WHEELS_RED(ChoseAngrySmile()));
}

void StopProgram() {
  std::abort();
}

struct AbortOnFailHandler : wheels::ITestFailHandler {
  void Fail(wheels::ITestPtr test, const std::string& error) override {
    const auto message{GetErrorMessage(test, error)};
    LogError(message);
    LogAngrySmile();
    StopProgram();
  }
};

struct SuccessHandler : wheels::ITestSuccessHandler {
  void Success(wheels::ITestPtr test, size_t milliseconds_duration) override {
    std::string time = std::to_string(milliseconds_duration) + "ms";
    const auto message{wheels::GetSuccessFormatter()->MakeMessage(test, time)};
    wheels::GetSuccessLogger()->Log(message);
  }
};

}

void detail::Fail(const char* file, int line) {
  wheels::GetTestFailHandler()->Fail(wheels::GetCurrentTest(), /*error=*/"");
}

std::string ChoseRandomHappySmiley() {
  static const std::vector<std::string> smileys{
      "(/^▽^)/", "☜(⌒▽⌒)☞", "ヽ(･∀･)ﾉ", "(•‿•)", "⊂(◉‿◉)つ", "{´◕ ◡ ◕｀}",
      "(☆^ー^☆)", "（＾_＾）", "٩( ᐛ )و"
  };
  return wheels::GetRandomValue(smileys);
}

void detail::AllTestPassed() {
  auto result_message{"ALL TESTS PASSED " + ChoseRandomHappySmiley()};
  wheels::PrintLine(WHEELS_GREEN(result_message));
}

void detail::ConfigurateTestFramework() {
  wheels::SetTestSuccessHandler(std::make_shared<SuccessHandler>());
  wheels::SetTestSuccessFormatter(std::make_shared<SuccessFormatter>());
  wheels::SetTestSuccessLogger(std::make_shared<ConsoleLogger>());

  wheels::SetTestFailHandler(std::make_shared<AbortOnFailHandler>());
  wheels::SetTestErrorFormatter(std::make_shared<ErrorFormatter>());
  wheels::SetTestErrorLogger(std::make_shared<ConsoleLogger>());
}

size_t RunWithTimer(const ITestPtr& test) {
  return wheels::RunWithTimer([test]() {
    test->Run();
  });
}

void detail::RunTests(const wheels::TestList& tests) {
  for (auto&& test : tests) {
    wheels::SetCurrentTest(test);
    const auto test_duration{RunWithTimer(test)};
    wheels::GetTestSuccessHandler()->Success(test, test_duration);
  }
}