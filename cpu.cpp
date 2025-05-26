#include "cpu.h"
#include <iostream>

void CPU::Reset() {
    pc = 0xBFC00000;
    std::cout << "CPU Reset. PC = " << std::hex << pc << std::endl;
}

void CPU::Step(Memory& memory) {
    uint32_t instr = memory.Read32(pc);
    std::cout << "Instruction: " << std::hex << instr << std::endl;
    pc += 4; // For now just skip forward
}