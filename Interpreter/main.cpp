#include "Chunk.h"
#include "ByteReader.h"
#include "VM.h"

int main() {
    Chunk chunk = {
        readFile("output.bin"),
        {}
    };

    VM vm;
    vm.run(chunk);

    return 0;
}