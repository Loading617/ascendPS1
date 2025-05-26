#ifndef _ascendPS1_bios_h_
#define _ascendPS1_bios_h_

#include <vector>
#include <Core/Core.h>
#include "memory.h"

class BIOS {
public:
    bool Load(const Upp::String& path, Memory& memory);

private:
    std::vector<uint8_t> data;
};

#endif
