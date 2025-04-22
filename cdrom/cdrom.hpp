#pragma once
#include <string>

class CDROM {
public:
    bool loadISO(const std::string& path);
    void readSector();
};
