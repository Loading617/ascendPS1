#pragma once
#include <cstdint>
#include <vector>

class Memory {
public:
    uint8_t read8(uint32_t addr);
    uint16_t read16(uint32_t addr);
    uint32_t read32(uint32_t addr);
    void write8(uint32_t addr, uint8_t val);
    void write16(uint32_t addr, uint16_t val);
    void write32(uint32_t addr, uint32_t val);
    void loadBIOS(const std::vector<uint8_t>& biosData);

    uint32_t read32(uint32_t addr);
    void write32(uint32_t addr, uint32_t value);

private:
    uint8_t ram[2 * 1024 * 1024] = {0};
    uint8_t bios[512 * 1024] = {0};
};
