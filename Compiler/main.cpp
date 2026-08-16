#include <iostream>
#include <bitset>
#include "AST/Operators/BinaryOperator.h"
#include "AST/Types/Integer.h"
#include "AST/ASTNode.h"
#include "AST/Types/Float.h"
#include "ByteWriter.h"

int main() {
    Integer int1(1);
    Float float2(2.5);
    Integer int3(3);

    BinaryOperator add1(&int1, &float2, ADDITION);
    BinaryOperator add2(&int3, &add1, MULTIPLICATION);
    add2.print();
    std::cout << std::endl << std::endl;

    std::vector<Byte> vec;
    add2.compile(vec);
    writeFile("output.bin", vec, {});

    for (const Byte& b : vec) {
        std::cout << std::bitset<8>(b) << std::endl;
    }

    return 0;
}