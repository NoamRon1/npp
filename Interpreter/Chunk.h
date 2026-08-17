#pragma once
#include <vector>
#include <cstdint>
#include "Opcodes.h"

struct Chunk {
    std::vector<Byte> code;
    std::vector<uint32_t> constants;

    void write(uint8_t byte) {
        code.push_back(byte);
    }

    //add constand + return index
    uint8_t addConstant(uint32_t value) {
        constants.push_back(value);
        return static_cast<uint8_t>(constants.size() - 1);
    }
};