//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 08/05/2022.
//

#include <wheels/test/test_framework.hpp>
#include <wheels/support/defer.hpp>

TEST_SUITE(Defer) {
  TEST(JustWork) {
    bool deferred{false};
    {
      wheels::Defer defer([&deferred]() {
        deferred = true;
      });
      ASSERT_FALSE(deferred);
    }
    ASSERT_TRUE(deferred);
  }

  TEST(TrueDefer) {
    int value{1};
    wheels::Defer defer([&value]() {
      ASSERT_EQ(value, 2);
    });
    value = 2;
  }

  TEST(Stack) {
    int shared_value{1};
    wheels::Defer last_defer([&shared_value]() {
      ASSERT_EQ(shared_value, 3);
    });
    wheels::Defer second_defer([&shared_value]() {
      ASSERT_EQ(shared_value, 2);
      ++shared_value;
    });
    wheels::Defer first_defer([&shared_value]() {
      ASSERT_EQ(shared_value, 1);
      ++shared_value;
    });
  }
}