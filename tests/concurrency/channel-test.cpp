//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 10/04/2022.
//

#include <wheels/test/test_framework.hpp>
#include <wheels/concurrency/channel.hpp>
#include <vector>

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
    auto optional{future.Get()};
    if (!optional.has_value()) {
      break;
    }
    result.push_back(optional.value());
  }
  promise.Put(std::move(result));
}

TEST_SUITE(Channel) {
  TEST(SequenceValues) {
      auto future{
          wheels::ViaChannel<int, std::vector<int>>(GenerateSequenceValues,
                                                    CreateVector)
      };
      auto vector{future.Get().value()};
      for (size_t i = 0; i < vector.size(); ++i) {
        ASSERT_EQ(vector[i], i);
      }
    }
}