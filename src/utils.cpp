#include <vector>
#include <cstdint>
#include <fstream>

std::vector<uint8_t> load_file(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    return std::vector<uint8_t>(std::istreambuf_iterator<char>(file), {});
}
