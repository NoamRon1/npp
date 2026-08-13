#include "Integer.h"
#include <iostream>
#include <cstring>

void Integer::compile(std::vector<Byte>& outputStream) const {
    outputStream.push_back(OpcodesBytes[Opcodes::PUSH]);
    size_t oldSize = outputStream.size();
    outputStream.resize(oldSize + sizeof(int32_t));

    std::memcpy(outputStream.data() + oldSize, &_value, sizeof(int32_t));
}

void Integer::print() {
    std::cout << _value;
}
