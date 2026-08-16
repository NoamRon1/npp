cmake_minimum_required(VERSION 4.2.2)
project(Compiler LANGUAGES CXX)

add_executable(Compiler
		main.cpp
		AST/ASTNode.h
		AST/Types/Integer.cpp
		AST/Types/Integer.h
		AST/Operators/BinaryOperator.cpp
		AST/Operators/BinaryOperator.h
		AST/Types/Float.cpp
		AST/Types/Float.h
		Opcodes.h
		ByteWriter.cpp
)


