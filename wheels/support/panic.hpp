//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/support/SourceLocation.hpp>
#include <wheels/support/StringBuiler.hpp>

namespace wheels::detail {
void Panic(SourceLocation where, const std::string& error);
}

#define WHEELS_PANIC(error) \
do {                            \
::wheels::detail::Panic(WHEELS_HERE, ::wheels::StringBuilder() << error); \
} while (false)
