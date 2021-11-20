//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/support/SourceLocation.hpp>

namespace wheels::support::detail {
void Panic(SourceLocation where, std::string_view error);
}

#define WHEELS_PANIC(error) \
do {                            \
::wheels::support::detail::Panic(WHEELS_HERE, error); \
} while (false)
