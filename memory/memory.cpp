#include "memory.hpp"
#include <cstring>

void Memory::loadBIOS(const std::vector<uint8_t>& biosData) {
    std::memcpy(bios, biosData.data(), std::min(biosData.size(), sizeof(bios)));
}

uint32_t Memory::read32(uint32_t addr) {
    if (addr >= 0x00000000 && addr < 0x00200000) {
        return *(uint32_t*)&ram[addr];
    } else if (addr >= 0x1FC00000 && addr < 0x1FC80000) {
        return *(uint32_t*)&bios[addr - 0x1FC00000];
    }
    return 0;
}

void Memory::write32(uint32_t addr, uint32_t value) {
    if (addr >= 0x00000000 && addr < 0x00200000) {
        *(uint32_t*)&ram[addr] = value;
    }
}
