#ifndef _ascendPS1_emulator_h_
#define _ascendPS1_emulator_h_

#include "cpu.h"
#include "memory.h"
#include "bios.h"

classclass Emulator {
public:
    Emulator();
    bool LoadBIOS(const String& path);
    void Start();

private:
    CPU cpu;
    Memory memory;
    BIOS bios;
};
#endif
