//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 09/04/2022.
//

#pragma once

#include <limits>
#include <random>
#include <string>

namespace detail {

template <typename T>
concept Array = requires(T c) {
  c[0];
  { c[0] } -> std::convertible_to<typename T::value_type>;
  c[0] = std::declval<typename T::value_type>();
  { c.size() } -> std::convertible_to<std::size_t>;
};

}

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

bool TossCoin(double eagle_probability = 0.5);

template <detail::Array A>
const typename A::value_type& GetRandomValue(const A& array) {
  int random_index{wheels::GetRandomValue(0, array.size() - 1)};
  return array[random_index];
}

}
