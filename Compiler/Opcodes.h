#pragma once
#include <map>
#include <cstdint>

using Byte = std::uint8_t;

enum Opcodes {
    PUSH,
    ADD,
    MUL
};

static std::map<Opcodes, Byte> OpcodesBytes = {
    {PUSH, 0},
    {ADD, 1},
    {MUL, 2}
};