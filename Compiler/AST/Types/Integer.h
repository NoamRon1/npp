#pragma once
#include "../ASTNode.h"
#include <string>

class Integer : public ASTNode {
public:
    Integer(int32_t value)
        : _value(value) {}

    ~Integer() override = default;
    void compile(std::vector<Byte>& outputStream) const override;
    void print() override;

private:
    int32_t _value;
};