//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 07/05/2022.
//

#pragma once

#include <string>

namespace wheels {

std::string GreenASCI();

std::string RedASCI();

std::string Reset();

}

#define WHEELS_GREEN(message) \
  wheels::GreenASCI() + (message) + wheels::Reset()

#define WHEELS_RED(message) \
  wheels::RedASCI() + (message) + wheels::Reset()
