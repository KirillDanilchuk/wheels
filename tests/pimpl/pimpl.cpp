//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/12/2021.
//

#include "pimpl.hpp"
#include <tests/pimpl/secret_library.hpp>

PublicClass::PublicClass() : pimpl_(42) {
  // pass
}

int PublicClass::GetValue() {
  return pimpl_->Value();
}

PublicClass::~PublicClass() = default;

PublicClass::PublicClass(PublicClass&&) noexcept = default;
PublicClass::PublicClass(const PublicClass&) = default;