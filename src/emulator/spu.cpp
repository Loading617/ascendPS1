#include "spu.hpp"
#include <iostream>

SPU::SPU() {
    std::cout << "SPU Initialized\n";
}

void SPU::reset() {
    std::cout << "SPU Reset\n";
}

void SPU::process_audio() {
    std::cout << "Processing Audio\n";
}