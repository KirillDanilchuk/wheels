//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 03/05/2022.
//

#pragma once

namespace wheels {

template <typename T>
T* Singleton() {
  static T instance;
  return &instance;
}

}
