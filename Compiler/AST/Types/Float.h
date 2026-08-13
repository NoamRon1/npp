#pragma once
#include "../ASTNode.h"
#include <string>

class Float : public ASTNode {
public:
    Float(float value)
        : _value(value) {}

    ~Float() override = default;
    compileReturnValue compile() override {}
    void print() override;

private:
    float _value;
};