//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 09/04/2022.
//

#include <wheels/test/test_framework.hpp>
#include <wheels/random/random.hpp>
#include <vector>

TEST_SUITE(RandomValue) {
  TEST(JustWork) {
    int value = wheels::GetRandomValue(0, 10);
    std::cout << "Random number: " << value << std::endl;

    std::vector<int> ints;
    ints.resize(1, 100);
    wheels::RandomFill(ints.begin(), ints.end());
    wheels::RandomFill(ints);
    ints = wheels::MakeRandomContainer<std::vector<int>>(10);
    auto random_string = wheels::MakeRandomString(15);
  }
}