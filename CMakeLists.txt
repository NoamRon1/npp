cmake_minimum_required(VERSION 4.2.2)
project(Npp LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Compiler)
add_subdirectory(Interpreter)
