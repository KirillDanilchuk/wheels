//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/support/panic.hpp>
#include <wheels/support/compiler.hpp>

#ifndef NDEBUG

#define WHEELS_ASSERT(condition, error)                                     \
do {                                                                        \
  if (!(condition)) {                                                       \
    WHEELS_PANIC("Assertion \'" << #condition << "\' failed: " << error);   \
  }                                                                         \
} while (false)

#else

#define WHEELS_ASSERT(condition, error) \
WHEELS_UNUSED(condition);               \
WHEELS_UNUSED(error)

#endif