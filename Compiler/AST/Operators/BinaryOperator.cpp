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
