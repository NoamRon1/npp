#pragma once
#include "../ASTNode.h"
#include <string>

class Integer : public ASTNode {
public:
    Integer(int value)
        : _value(value) {}

    ~Integer() override = default;
    compileReturnValue compile() override {}
    void print() override;

private:
    int _value;
};