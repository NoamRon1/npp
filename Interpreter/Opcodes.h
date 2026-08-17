#pragma once
#include <cstdint>

using Byte = uint8_t;

enum OpCode : uint8_t {
    OP_PUSH,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_HALT,
};

