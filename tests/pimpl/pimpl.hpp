//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/12/2021.
//

#pragma once

#include <wheels/support/pimpl.hpp>

class SecretClass;

class PublicClass {
 public:
  PublicClass();
  ~PublicClass();
  PublicClass(const PublicClass&);
  PublicClass(PublicClass&&) noexcept;
  int GetValue();

 private:
  wheels::Pimpl<SecretClass, /*kSize=*/4, /*kAligned=*/4> pimpl_;
};