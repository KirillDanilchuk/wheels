//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 09/04/2022.
//

#include <gtest/gtest.h>
#include <wheels/random/random.hpp>

TEST(RandomValue, JustWork) {
  int value = wheels::GetRandomValue(0, 10);
  std::cout << "Random number: " << value << std::endl;
}
