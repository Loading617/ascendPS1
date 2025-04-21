#pragma once
#include <vector>
#include <string>

class BIOS {
public:
    static std::vector<uint8_t> load(const std::string& path);
};
