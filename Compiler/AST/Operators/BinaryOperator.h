#pragma once
#include "../ASTNode.h"

enum BinaryOperatorType {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};

class BinaryOperator : public ASTNode {
public:
    BinaryOperator(ASTNode* left, ASTNode* right, BinaryOperatorType operatorType)
        : _left(left),
          _right(right),
          _operatorType(operatorType) {}

    void print() override;
    void compile(std::vector<Byte>& outputStream) const override;
    ~BinaryOperator() override = default;

private:
    ASTNode* _left;
    ASTNode* _right;
    BinaryOperatorType _operatorType;
};
