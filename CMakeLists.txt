cmake_minimum_required(VERSION 3.14)

project(wheels)

include(cmake/CompileOption.cmake)

add_subdirectory(wheels)

option(ENABLE_SAMPLES "Enable all samples for this library" OFF)
option(ENABLE_TESTS "Enable all tests for this library" OFF)

if(ENABLE_SAMPLES)
    add_subdirectory(samples)
endif()

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()