#include "emulator.h"

Emulator::Emulator() {}

bool Emulator::LoadBIOS(const String& path) {
    return bios.Load(path, memory);
}

void Emulator::Start() {
    cpu.Reset();
    for (int i = 0; i < 100; i++) { // Example: Run 100 cycles
        cpu.Step(memory);
    }
}
