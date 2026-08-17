#include <iostream>
#include <bitset>
#include "AST/Operators/BinaryOperator.h"
#include "AST/Types/Integer.h"
#include "AST/ASTNode.h"
#include "ByteWriter.h"

int main() {
    Integer int1(1);
    Integer int2(2);
    Integer int3(3);

    BinaryOperator add1(&int1, &int2, ADDITION);
    BinaryOperator add2(&int3, &add1, MULTIPLICATION);
    add2.print();
    std::cout << std::endl << std::endl;

    std::vector<Byte> code;
    add2.compile(code);

    code.push_back(OpcodesBytes[Opcodes::HALT]);
    writeFile("output.bin", code, {});

    for (const Byte& b : code) {
        std::cout << std::bitset<8>(b) << std::endl;
    }

    return 0;
}