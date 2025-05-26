#include "bios.h"

bool BIOS::Load(const Upp::String& path, Memory& memory) {
    Upp::FileIn in(path);
    if (!in.IsOpen()) return false;

    data = std::vector<uint8_t>(in.GetLeft(), 0);
    in.Get(&data[0], data.size());
    memory.LoadBIOS(data);
    return true;
}
