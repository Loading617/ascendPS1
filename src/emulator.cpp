#include "emulator.hpp"
#include <iostream>

Emulator::Emulator() {
    initialize();
}

Emulator::~Emulator() {
    stop();
}

void Emulator::initialize() {
    std::cout << "Initializing emulator..." << std::endl;
    
}

void Emulator::loadROM(const std::string& filepath) {
    std::cout << "Loading ROM: " << filepath << std::endl;
    
}

void Emulator::run() {
    std::cout << "Running emulator..." << std::endl;
    
    while (true) {
        executeFrame();
    }
}

void Emulator::stop() {
    std::cout << "Stopping emulator..." << std::endl;
    
}

void Emulator::executeFrame() {
    
}
