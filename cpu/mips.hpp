#pragma once
#include <cstdint>
#include "../memory/memory.hpp"

class MIPS {
public:
    MIPS(Memory& mem);
    void reset();
    void step();
    void executeNextInstruction();
    void loadBIOS(const char* path);

private:
    uint32_t pc;
    uint32_t regs[32] = {0};
    Memory& memory;
    uint32_t hi, lo;

    uint8_t memory[0x200000];

    void decodeAndExecute(uint32_t instruction);
};
