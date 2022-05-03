//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/05/2022.
//

#include <wheels/test/test.hpp>

TEST_SUITE(JustSuite) {
  TEST(JustTest) {
    // pass
  }
}

TEST_SUITE(Assert) {
  TEST(True) {
    ASSERT_TRUE(true);
  }
}

RUN_ALL_TESTS();