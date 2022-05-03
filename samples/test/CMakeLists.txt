cmake_minimum_required(VERSION 3.14)
project(test_sample)

file(GLOB SOURCES *.cpp)

link_libraries(wheels)

add_executable(${PROJECT_NAME} ${SOURCES})

