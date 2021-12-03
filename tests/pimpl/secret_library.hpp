//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/12/2021.
//

#pragma once

#define SECRET

class SecretClass {
 public:
  explicit SecretClass(int value) : value_{value} {
    // pass
  }

  SecretClass(SecretClass&&) = default;
  SecretClass(const SecretClass&) = default;

  void SetValue(int value) {
    value_ = value;
  }

  int Value() {
    return value_;
  }

 private:
  int value_;
};
