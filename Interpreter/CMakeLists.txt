cmake_minimum_required(VERSION 4.2.2)
project(Interpreter LANGUAGES CXX)

add_executable(Interpreter
	main.cpp
        VM.cpp
        VM.h
		chunk.h
)
