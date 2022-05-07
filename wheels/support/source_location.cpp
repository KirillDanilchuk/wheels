//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <iostream>
#include <wheels/support/source_location.hpp>

namespace wheels {

std::ostream& operator<<(std::ostream& out,
                         const wheels::SourceLocation& where) {
  out << where.file_ << ":" << where.function_ << "[Line " << where.line_
      << "]";
  return out;
}

} // namespace wheels