//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 10/04/2022.
//

#include <wheels/concurrency/channel.hpp>
#include <wheels/io/pretty_std.hpp>
#include <vector>
#include <wheels/time/timer.hpp>
#include <iostream>

void GenerateSequenceValues(wheels::Promise<int> promise) {
  wheels::Timer<std::chrono::nanoseconds> timer;
  for (int i = 0; i < 10; ++i) {
    promise.Put(i);
  }
  std::cout << "Producer elapsed: " << timer.Elapsed() << "ns" << std::endl;
  promise.CloseChannel();
}

void CreateVector(wheels::Future<int> future,
                  wheels::Promise<std::vector<int>> promise) {
  wheels::Timer<std::chrono::nanoseconds> timer;
  std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  std::vector<int> result;
  while (true) {
    auto optional{future.Get()};
    if (!optional.has_value()) {
      break;
    }
    result.push_back(optional.value());
  }
  std::cout << "Consumer elapsed: " << timer.Elapsed() << "ns" << std::endl;
  promise.Put(std::move(result));
}

int main() {
  auto future{wheels::ViaChannel<int, std::vector<int>>(GenerateSequenceValues,
                                                        CreateVector)};
  auto vector{future.Get().value()};
  std::cout << vector << std::endl;
}