#pragma once
#include <map>
#include <cstdint>

using Byte = std::uint8_t;

enum Opcodes {
    PUSH,
    ADD,
    SUB,
    MUL,
    DIV,
    HALT
};

static std::map<Opcodes, Byte> OpcodesBytes = {
    {PUSH, 0},
    {ADD, 1},
    {SUB, 2},
    {MUL, 3},
    {DIV, 4},
    {HALT, 5}
};