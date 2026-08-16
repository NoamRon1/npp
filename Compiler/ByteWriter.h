#pragma once
#include <string>
#include <vector>
#include "Opcodes.h"

void writeFile(
    const std::string& filename,
    const std::vector<Byte>& code,
    const std::vector<Byte>& consts
);
