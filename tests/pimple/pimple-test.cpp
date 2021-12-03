//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/12/2021.
//

#include <gtest/gtest.h>
#include <tests/pimple/pimple.hpp>

TEST(Pimple, JustWork) {
#ifdef SECRET
  ASSERT_TRUE(false);
#endif

  PublicClass value;
  ASSERT_EQ(value.GetValue(), 42);
}