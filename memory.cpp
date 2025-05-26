#include "memory.h"

Memory::Memory() : ram(2 * 1024 * 1024, 0) {} // 2MB RAM

uint32_t Memory::Read32(uint32_t addr) const {
    if (addr < ram.size() - 4)
        return *(uint32_t*)&ram[addr];
    return 0;
}

void Memory::LoadBIOS(const std::vector<uint8_t>& bios) {
    for (size_t i = 0; i < bios.size() && i < ram.size(); ++i) {
        ram[i] = bios[i];
    }
}
