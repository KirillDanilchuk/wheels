//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/05/2022.
//

#include <wheels/test/test.hpp>
#include <wheels/support/singleton.hpp>

namespace wheels {

namespace {

ITestPtr current_test;

}

ITestPtr CurrentTest() noexcept {
  return current_test;
}

TestList& GetAllTests() {
  return *Singleton<TestList>();
}

void RegisterTest(ITestPtr test) {
  Singleton<TestList>()->push_back(std::move(test));
}

void SetCurrentTest(ITestPtr test) {
  current_test = std::move(test);
}

ITestPtr GetCurrentTest() {
  return current_test;
}

}
