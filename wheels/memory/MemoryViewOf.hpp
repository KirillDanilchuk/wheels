//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <vector>
#include <string>
#include <wheels/memory/MemoryView.hpp>

inline MemoryView MemoryViewOf(std::vector<char>& v) {
  return MemoryView{v.data(), v.size()};
}

inline MemoryView MemoryViewOf(std::string& str) {
  return MemoryView{str.data(), str.size()};
}

template <size_t N>
inline MemoryView MemoryViewOf(char (&arr)[N]) {
  return MemoryView{arr, N};
}