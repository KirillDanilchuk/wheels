//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 09/04/2022.
//

#pragma once

#include <limits>
#include <random>
#include <string>

namespace wheels {

std::mt19937& GetCurrentGenerator();

int GetRandomValue(int left = 0, int right = std::numeric_limits<int>::max());

template <typename Iter>
void RandomFill(Iter begin, Iter end, int left = 0,
                int right = std::numeric_limits<int>::max()) {
  for (auto it = begin; it != end; ++it) {
    *it = GetRandomValue(left, right);
  }
}

template <typename Container>
void RandomFill(Container& container, int left = 0,
                int right = std::numeric_limits<int>::max()) {
  RandomFill(container.begin(), container.end(), left, right);
}

template <typename Container>
Container MakeRandomContainer(size_t size, int left = 0,
                              int right = std::numeric_limits<int>::max()) {
  Container container;
  std::generate_n(std::back_inserter(container), size,
                  GetCurrentGenerator());
  return container;
}

std::string MakeRandomString(size_t size);

double GetProbability();

bool TossCoin(double eagle_probability);

}
