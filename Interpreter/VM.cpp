#include "VM.h"
#include <cstring>
#include "Chunk.h"
#include <iostream>

void VM::push(double value) {
    *_sp = value;
    _sp++;
}

double VM::pop() {
    _sp--;
    return *_sp;
}

void VM::run(const Chunk& chunk) {
    _sp = _stack;


    const uint8_t* ip = chunk.code.data();

    while (true) {
        Byte instruction = *ip++;

        switch (instruction) {
            case OP_PUSH: {
                uint32_t value;
                std::memcpy(&value, ip, sizeof(value));
                push(value);
                ip += 4;


                std::cout << "Pushed: " << value << std::endl;
                break;
            }
            case OP_ADD: {
                double b = pop();
                double a = pop();
                push(a + b);

                std::cout << "Added: " << a << " + " << b << std::endl;
                break;
            }
            case OP_SUBTRACT: {
                double b = pop();
                double a = pop();
                push(a - b);

                std::cout << "Subtracted: " << a << " - " << b << std::endl;
                break;
            }
            case OP_MULTIPLY: {
                double b = pop();
                double a = pop();
                push(a * b);

                std::cout << "Multiplied: " << a << " * " << b << std::endl;
                break;
            }
            case OP_DIVIDE: {
                double b = pop();
                double a = pop();
                push(a / b);

                std::cout << "Divided: " << a << " / " << b << std::endl;
                break;
            }
            case OP_HALT: {
                std::cout << "Halted!" << std::endl;
                std::cout << "result: " << *(_sp - 1) << "\n";
                return;
            }
        }
    }
}