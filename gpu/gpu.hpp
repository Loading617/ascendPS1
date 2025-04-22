#pragma once
#include <cstdint>

class GPU {
public:
    void reset();
    void writeGP0(uint32_t val);
    void writeGP1(uint32_t val);
    void renderFrame();

private:
    uint16_t vram[1024 * 512];
};
