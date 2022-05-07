//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 08/05/2022.
//

#pragma once

namespace wheels {

template <typename T>
concept Callable = requires(T value) {
  value();
};

}