//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 06/12/2021.
//

#pragma once

#include <cstdlib>
#include <wheels/memory/MytableBuffer.hpp>

namespace wheels {
class IReader {
 public:
  Result<size_t> Read(MutableBuffer buffer);
};

}



