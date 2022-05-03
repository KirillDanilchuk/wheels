//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/05/2022.
//

#include <wheels/test/fail_handler.hpp>
#include <wheels/support/assert.hpp>

namespace wheels {

static FailHandlerPtr current_fail_handler;

void SetTestFailHandler(FailHandlerPtr fail_handler) {
  current_fail_handler = std::move(fail_handler);
}

FailHandlerPtr GetTestFailHandler() {
  WHEELS_ASSERT(current_fail_handler, "Fail handler isn't install");
  return current_fail_handler;
}

}