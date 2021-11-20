//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/support/panic.hpp>

int main(int argc, char** argv) {
  WHEELS_PANIC("Error message 1 " << "Error message 2 " << 3);
  return 0;
}