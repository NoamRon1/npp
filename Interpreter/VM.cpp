#include "VM.h"
#include "chunk.h"
#include <iostream>

void VM::push(double value) {
    *_sp = value;
    _sp++;
}

double VM::pop() {
    _sp--;
    return *_sp;
}

void VM::run(const chunk& chunk) {
    _sp = _stack;


    const uint8_t* ip = chunk.code.data();

    while (true) {
        uint8_t instruction = *ip++;

        switch (instruction) {
            case OP_CONSTANT: {
                uint8_t constIndex = *ip++;
                push(chunk.constants[constIndex]);
                break;
            }
            case OP_ADD: {
                double b = pop();
                double a = pop();
                push(a + b);
                break;
            }
            case OP_SUBTRACT: {
                double b = pop();
                double a = pop();
                push(a - b);
                break;
            }
            case OP_MULTIPLY: {
                double b = pop();
                double a = pop();
                push(a * b);
                break;
            }
            case OP_DIVIDE: {
                double b = pop();
                double a = pop();
                push(a / b);
                break;
            }
            case OP_HALT: {
                std::cout << "result: " << *(_sp - 1) << "\n";
                return;
            }
        }
    }
}