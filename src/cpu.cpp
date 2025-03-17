#include "cpu.hpp"
#include <iostream>

CPU::CPU(Memory& mem) : memory(mem) {
    reset();
}

void CPU::reset() {
    registers.fill(0);
    pc = 0xBFC00000;
    hi = lo = 0;
}

void CPU::step() {
    uint32_t instruction = memory.read32(pc);
    pc += 4;
    execute_instruction(instruction);
}

void CPU::execute_instruction(uint32_t instruction) {
    uint8_t opcode = (instruction >> 26) & 0x3F;

    switch (opcode) {
        case 0x00: {
            uint8_t funct = instruction & 0x3F;
            std::cout << "R-Type funct: " << (int)funct << std::endl;
            break;
        }
        case 0x02: {
            uint32_t target = instruction & 0x3FFFFFF;
            pc = (pc & 0xF0000000) | (target << 2);
            std::cout << "Jump to: " << std::hex << pc << std::endl;
            break;
        }
        case 0x08: {
            uint8_t rt = (instruction >> 16) & 0x1F;
            uint8_t rs = (instruction >> 21) & 0x1F;
            int16_t imm = instruction & 0xFFFF;
            registers[rt] = registers[rs] + imm;
            std::cout << "ADDI: R" << (int)rt << " = " << registers[rt] << std::endl;
            break;
        }
        default:
            std::cout << "Unknown instruction: " << std::hex << instruction << std::endl;
    }
}
