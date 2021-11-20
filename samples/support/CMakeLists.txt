cmake_minimum_required(VERSION 3.14)
project(support_sample)

link_libraries(wheels)

add_executable(panic_sample panic.cpp)

add_executable(assert_sample assert.cpp)


