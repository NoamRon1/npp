#pragma once
#include <vector>
#include "../Opcodes.h"

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void compile(std::vector<Byte>& outputStream) const = 0;
    virtual void print() = 0;
};
