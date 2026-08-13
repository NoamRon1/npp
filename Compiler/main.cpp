#include <pthread.h>

#include "AST/Operators/BinaryOperator.h"
#include "AST/Types/Integer.h"
#include "AST/ASTNode.h"
#include "AST/Types/Float.h"

int main() {
    Integer int1(1);
    Float float2(2.5);
    Integer int3(3);

    BinaryOperator add1(&int1, &float2, ADDITION);
    BinaryOperator add2(&int3, &add1, MULTIPLICATION);
    add2.print();

    return 0;
}