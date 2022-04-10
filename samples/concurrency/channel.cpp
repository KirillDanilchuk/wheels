//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 10/04/2022.
//

#include <wheels/concurrency/channel.hpp>
#include <wheels/io/pretty_std.hpp>
#include <vector>
#include <iostream>

void GenerateSequenceValues(wheels::Promise<int> promise) {
  for (int i = 0; i < 10; ++i) {
    promise.Put(i);
  }
  promise.CloseChannel();
}

void CreateVector(wheels::Future<int> future,
                  wheels::Promise<std::vector<int>> promise) {
  std::vector<int> result;
  while (true) {
    auto optional{future.GetOptional()};
    if (!optional.has_value()) {
      break;
    }
    result.push_back(optional.value());
  }
  promise.Put(std::move(result));
}

int main() {
  auto future{wheels::ViaChannel<int, std::vector<int>>(GenerateSequenceValues,
                                                        CreateVector)};
  auto vector{future.GetOptional().value()};
  std::cout << vector << std::endl;
}