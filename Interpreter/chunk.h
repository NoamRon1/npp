#pragma once
#include <vector>
#include <cstdint>

enum OpCode : uint8_t {
    OP_PUSH,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_HALT,
};

struct chunk {
    std::vector<uint8_t> code;
    std::vector<double> constants;

    void write(uint8_t byte) {
        code.push_back(byte);
    }

    //add constand + return index
    uint8_t addConstant(double value) {
        constants.push_back(value);
        return static_cast<uint8_t>(constants.size() - 1);
    }
};