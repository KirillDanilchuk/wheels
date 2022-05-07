//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/05/2022.
//

#include "wheels/test/test_framework.hpp"
#include <thread>

TEST_SUITE(JustSuite) {
  TEST(JustTest) {
    // pass
  }
}

TEST_SUITE(Assert) {
  TEST(True) {
    ASSERT_TRUE(true);
  }
  TEST(False) {
    ASSERT_FALSE(false);
  }
  TEST(Eq) {
    ASSERT_EQ(1, 1);
  }
  TEST(NotEq) {
    ASSERT_NOT_EQ(1, 1 + 1);
  }
  TEST(Less) {
    ASSERT_LESS(1, 2);
  }
  TEST(LessOrEq) {
    ASSERT_LESS_OR_EQ(1, 2);
    ASSERT_LESS_OR_EQ(1, 1);
  }
  TEST(Great) {
    ASSERT_GREAT(2, 1);
  }
  TEST(GreatOrEq) {
    ASSERT_GREAT_OR_EQ(2, 1);
    ASSERT_GREAT_OR_EQ(2, 2);
  }

  TEST(WithMessage) {
    ASSERT_EQ(1, 1);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  TEST(Failure) {
    ASSERT_TRUE(false);
  }
}

RUN_ALL_TESTS();