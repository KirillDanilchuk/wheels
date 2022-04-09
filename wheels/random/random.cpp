//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 09/04/2022.
//

#include <wheels/random/random.hpp>
#include <random>

namespace wheels {

int GetRandomValue(int left, int right) {
  static std::random_device random_device;
  static std::mt19937 generator(random_device());
  std::uniform_int_distribution<> distribution{left, right};
  return distribution(generator);
}

}