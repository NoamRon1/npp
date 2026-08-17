#include "VM.h"
#include <cstring>
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
            case OP_PUSH: {
                uint8_t value;
                std::memcpy(&value, ip, sizeof(value));
                push(value);
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