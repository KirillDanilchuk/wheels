//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/12/2021.
//

#include <wheels/test/test_framework.hpp>
#include "pimpl.hpp"

TEST_SUITE(Pimple) {
  TEST(JustWork) {
#ifdef SECRET
    ASSERT_TRUE(false);
#endif

    PublicClass value;
    ASSERT_EQ(value.GetValue(), 42);
  }
}