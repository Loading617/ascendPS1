#include "memory.hpp"
#include <iostream>

Memory::Memory() {
    ram.resize(2 * 1024 * 1024, 0);
    bios.resize(512 * 1024, 0);
}

uint32_t Memory::read32(uint32_t address) {
    address &= 0x1FFFFFFF;

    if (address < 0x200000) {
        return *(uint32_t*)&ram[address];
    } else if (address >= 0x1FC00000 && address < 0x1FC80000) {
        uint32_t bios_offset = address - 0x1FC00000;
        return *(uint32_t*)&bios[bios_offset];
    }

    std::cout << "Unhandled read32 from: " << std::hex << address << std::endl;
    return 0;
}

void Memory::write32(uint32_t address, uint32_t value) {
    address &= 0x1FFFFFFF;  

    if (address < 0x200000) {  
        *(uint32_t*)&ram[address] = value;
    } else {
        std::cout << "Unhandled write32 to: " << std::hex << address << " = " << value << std::endl;
    }
}

uint8_t Memory::read8(uint32_t address) {
    address &= 0x1FFFFFFF;

    if (address < 0x200000) {  
        return ram[address];
    } else if (address >= 0x1FC00000 && address < 0x1FC80000) {  
        uint32_t bios_offset = address - 0x1FC00000;
        return bios[bios_offset];
    }

    std::cout << "Unhandled read8 from: " << std::hex << address << std::endl;
    return 0;
}

void Memory::write8(uint32_t address, uint8_t value) {
    address &= 0x1FFFFFFF;

    if (address < 0x200000) {  
        ram[address] = value;
    } else {
        std::cout << "Unhandled write8 to: " << std::hex << address << " = " << (int)value << std::endl;
    }
}

void Memory::load_bios(const std::vector<uint8_t>& bios_data) {
    if (bios_data.size() <= bios.size()) {
        std::copy(bios_data.begin(), bios_data.end(), bios.begin());
        std::cout << "BIOS loaded successfully!" << std::endl;
    } else {
        std::cout << "BIOS file is too large!" << std::endl;
    }
}
