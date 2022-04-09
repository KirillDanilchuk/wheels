//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 09/04/2022.
//

#include <wheels/random/random.hpp>
#include <random>

namespace wheels {

std::mt19937& GetCurrentGenerator() {
  static std::random_device random_device;
  static std::mt19937 generator(random_device());
  return generator;
}

int GetRandomValue(int left, int right) {
  std::uniform_int_distribution<> distribution{left, right};
  return distribution(GetCurrentGenerator());
}

std::string MakeRandomString(size_t size) {
  return MakeRandomContainer<std::string>(size,
                                          std::numeric_limits<char>::min(),
                                          std::numeric_limits<char>::max());
}

}