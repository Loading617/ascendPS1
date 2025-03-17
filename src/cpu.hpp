#ifndef CPU_HPP
#define CPU_HPP

#include <cstdint>
#include <array>
#include "memory.hpp"

class CPU {
public:
    CPU(Memory& memory);
    void reset();
    void step();

private:
    void execute_instruction(uint32_t instruction);

    std::array<uint32_t, 32> registers;
    uint32_t pc;
    uint32_t hi, lo;

    Memory& memory;
};

#endif
