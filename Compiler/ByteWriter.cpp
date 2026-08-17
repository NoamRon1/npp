#include "ByteWriter.h"
#include <cstring>
#include <fstream>

void writeFile(const std::string& filename, const std::vector<Byte>& code, const std::vector<Byte>& consts) {
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (!file) {
        throw std::runtime_error("Could not open file for writing");
    }

    // file signature:
    file.write("NN\0\0", 4);

    // consts length
    char bytes[sizeof(uint32_t)];
    uint32_t constsLength = consts.size() * sizeof(Byte);
    std::memcpy(bytes, &constsLength, sizeof(uint32_t));
    file.write(bytes, sizeof(uint32_t));

    // consts:
    file.write(reinterpret_cast<const char*>(consts.data()), constsLength);

    // code:
    uint32_t codeLength = code.size() * sizeof(Byte);
    file.write(reinterpret_cast<const char*>(code.data()), codeLength);

    file.close();
}
