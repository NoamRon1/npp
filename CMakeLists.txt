cmake_minimum_required(VERSION 4.3)
project(Npp LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Compiler)
add_subdirectory(Interpreter)
