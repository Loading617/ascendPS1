#ifndef _ascendPS1_memory_h_
#define _ascendPS1_memory_h_

#include <vector>
#include <cstdint>

class Memory {
public:
    Memory();
    uint32_t Read32(uint32_t addr) const;
    void LoadBIOS(const std::vector<uint8_t>& bios);

private:
    std::vector<uint8_t> ram;
};

#endif
