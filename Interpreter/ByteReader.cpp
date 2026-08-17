#include "ByteReader.h"

#include <cstring>
#include <fstream>
#include <ios>

std::vector<Byte> readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        throw std::runtime_error("Could not open file for reading");
    }

    char signature[4];
    file.read(signature, 4);

    if (std::string(signature) != std::string("NN\0\0")) {
        throw std::runtime_error("File does not contain the signature");
    }

    char constsLengthChar[sizeof(uint32_t)];
    file.read(constsLengthChar, sizeof(uint32_t));

    uint32_t constsLength;
    std::memcpy(&constsLength, constsLengthChar, sizeof(uint32_t));

    char* constsChar = new char[constsLength];
    file.read(constsChar, constsLength);

    std::vector<Byte> consts(constsChar, constsChar + constsLength);

    file.seekg(0, std::ios_base::end); // put curser at end of file
    size_t fileLength = file.tellg(); // get file length
    file.seekg(4 + sizeof(uint32_t) + constsLength, std::ios_base::beg); // put curser at start of code section

    size_t codeLength = fileLength - (4 + sizeof(uint32_t) + constsLength);
    char* codeChar = new char[codeLength];
    file.read(codeChar, codeLength);

    std::vector<Byte> code(codeChar, codeChar + codeLength);

    delete[] constsChar;
    delete[] codeChar;

    return code;
}
