#include "cdrom.hpp"
#include <fstream>
#include <iostream>

CDROM::CDROM() {}

bool CDROM::load_disc(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    
    if (!file) {
        std::cerr << "Failed to load game: " << filename << std::endl;
        return false;
    }

    disc_data = {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
    std::cout << "Game loaded successfully! Size: " << disc_data.size() << " bytes" << std::endl;
    
    return true;
}

std::vector<uint8_t> CDROM::read_sector(uint32_t sector) {
    uint32_t offset = sector * 2352;
    if (offset + 2352 > disc_data.size()) {
        std::cerr << "Read out of bounds: sector " << sector << std::endl;
        return {};
    }
    
    return std::vector<uint8_t>(disc_data.begin() + offset, disc_data.begin() + offset + 2352);
}
