//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 07/05/2022.
//

#include <wheels/io/color.hpp>

namespace wheels {

std::string GreenASCI() {
  return "\033[1;32m";
}

std::string RedASCI() {
  return "\033[1;31m";
}

std::string Reset() {
  return "\033[0m";
}

}