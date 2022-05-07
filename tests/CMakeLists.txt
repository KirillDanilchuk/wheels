cmake_minimum_required(VERSION 3.14)
project(tests)

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE wheels)

get_filename_component(TEST_INCLUDE_PATH ".." ABSOLUTE)
target_include_directories(${PROJECT_NAME} PUBLIC ${TEST_INCLUDE_PATH})