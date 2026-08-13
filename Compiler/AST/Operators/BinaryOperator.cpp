#include "BinaryOperator.h"
#include <iostream>

void BinaryOperator::print() {
    std::cout << "(";
    _left->print();

    switch (_operatorType) {
    case ADDITION:
        std::cout << " + ";
        break;
    case SUBTRACTION:
        std::cout << " - ";
        break;
    case MULTIPLICATION:
        std::cout << " * ";
        break;
    case DIVISION:
        std::cout << " / ";
        break;
    }

    _right->print();
    std::cout << ")";
}

void BinaryOperator::compile(std::vector<Byte>& outputStream) const {
    _left->compile(outputStream);
    _right->compile(outputStream);

    Byte operation;
    switch (_operatorType) {
    case ADDITION:
        operation = OpcodesBytes[Opcodes::ADD];
        break;
    case SUBTRACTION:
        operation = OpcodesBytes[Opcodes::ADD];
        break;
    case MULTIPLICATION:
        operation = OpcodesBytes[Opcodes::MUL];
        break;
    case DIVISION:
        operation = OpcodesBytes[Opcodes::MUL];
        break;
    }
    outputStream.push_back(operation);
}
