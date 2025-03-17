#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstdint>
#include <vector>

class Memory {
public:
    Memory();
    uint32_t read32(uint32_t address);
    void write32(uint32_t address, uint32_t value);

    uint8_t read8(uint32_t address);
    void write8(uint32_t address, uint8_t value);

    void load_bios(const std::vector<uint8_t>& bios_data);

private:
    std::vector<uint8_t> ram;
    std::vector<uint8_t> bios;
};

#endif
