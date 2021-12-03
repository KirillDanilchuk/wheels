cmake_minimum_required(VERSION 3.14)

project(wheels)

include(cmake/CompileOption.cmake)

add_subdirectory(wheels)
add_subdirectory(samples)
add_subdirectory(tests)