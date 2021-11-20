cmake_minimum_required(VERSION 3.14)
project(io_sample)

link_libraries(wheels)

add_executable(input_sample input.cpp)
add_executable(output_sample output.cpp)
add_executable(printer_sample printer.cpp)
add_executable(pretty_std_sample pretty_std.cpp)


