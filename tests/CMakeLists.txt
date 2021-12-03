cmake_minimum_required(VERSION 3.14)
project(tests)

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE wheels)

include(FetchContent)

# GTest
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main)

get_filename_component(TEST_INCLUDE_PATH ".." ABSOLUTE)
target_include_directories(${PROJECT_NAME} PUBLIC ${TEST_INCLUDE_PATH})