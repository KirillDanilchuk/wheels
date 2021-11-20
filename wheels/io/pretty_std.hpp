//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#pragma once

#include <vector>
#include <iostream>

template <typename T, typename Allocator>
std::ostream& operator<<(std::ostream& out,
                         const std::vector<T, Allocator>& vector) {
  if (vector.empty()) {
    out << "Vector is empty. Capacity:" << vector.capacity();
    return out;
  }
  out << "[size:" << vector.size() << ", capacity:" << vector.capacity()
      << "] {" << vector.front();
  for (size_t i{1}; i < vector.size(); ++i) {
    out << ", " << vector[i];
  }
  out << "}";
  return out;
}
