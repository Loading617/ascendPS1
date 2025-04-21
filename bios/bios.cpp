#include "bios.hpp"
#include <fstream>

std::vector<uint8_t> BIOS::load(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    return std::vector<uint8_t>(std::istreambuf_iterator<char>(file), {});
}
