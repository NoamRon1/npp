#include "Float.h"
#include <cstring>
#include <iostream>

void Float::compile(std::vector<Byte>& outputStream) const {
    outputStream.push_back(OpcodesBytes[Opcodes::PUSH]);
    size_t oldSize = outputStream.size();
    outputStream.resize(oldSize + sizeof(float));

    std::memcpy(outputStream.data() + oldSize, &_value, sizeof(float));
}

void Float::print() {
    std::cout << _value;
}
