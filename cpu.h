#ifndef _ascendPS1_cpu_h_
#define _ascendPS1_cpu_h_

class CPU {
public:
    void Reset();
    void Step(Memory& memory);
private:
    uint32_t pc = 0xBFC00000; // BIOS entry point
};

#endif
