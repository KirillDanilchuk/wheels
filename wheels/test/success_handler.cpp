//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/05/2022.
//

#include <wheels/test/success_handler.hpp>
#include <wheels/support/assert.hpp>

namespace wheels {

static SuccessHandlerPtr current_success_handler;

void SetTestSuccessHandler(SuccessHandlerPtr success_handler) {
  current_success_handler = std::move(success_handler);
}

SuccessHandlerPtr GetTestSuccessHandler() {
  WHEELS_ASSERT(current_success_handler, "Success handler isn't install");
  return current_success_handler;
}

}