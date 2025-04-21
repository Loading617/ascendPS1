#include "mips.hpp"
#include <cstring>
#include <iostream>

MIPS::MIPS(Memory& mem) : memory(mem) {}
void MIPS::reset() {
    pc = 0xbfc00000;
    std::memset(regs, 0, sizeof(regs));
    hi = lo = 0;
}

void MIPS::step() {
    uint32_t instruction = memory.read32(pc);
    decodeAndExecute(instruction);
    pc += 4;
}

void MIPS::loadBIOS(const char* path) {
    
}

void MIPS::executeNextInstruction() {
    uint32_t instr = 0;
    switch (opcode) {
        case 0x00: {
            uint32_t funct = instr & 0x3F;
            uint32_t rs = (instr >> 21) & 0x1F;
            uint32_t rt = (instr >> 16) & 0x1F;
            uint32_t rd = (instr >> 11) & 0x1F;
            if (funct == 0x20) {
                regs[rd] = regs[rs] + regs[rt];
            }
            break;
        }
        case 0x08: {
            uint32_t rs = (instr >> 21) & 0x1F;
            uint32_t rt = (instr >> 16) & 0x1F;
            int16_t imm = instr & 0xFFFF;
            regs[rt] = regs[rs] + imm;
            break;
        }
        {
        default:
            std::cout << "Unknown opcode: 0x" << std::hex << opcode << "\n";
            break;
    }
}
    decodeAndExecute(instr);
}

void MIPS::decodeAndExecute(uint32_t instruction) {
    
}
