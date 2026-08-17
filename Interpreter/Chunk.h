#pragma once
#include <vector>
#include <cstdint>
#include "Opcodes.h"

struct Chunk {
    std::vector<Byte> code;
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