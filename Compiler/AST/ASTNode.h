#pragma once

typedef void compileReturnValue;

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual compileReturnValue compile() = 0;
    virtual void print() = 0;
};