#ifndef CDROM_HPP
#define CDROM_HPP

#include <vector>
#include <string>
#include <cstdint>

class CDROM {
public:
    CDROM();
    bool load_disc(const std::string& filename);
    std::vector<uint8_t> read_sector(uint32_t sector);

private:
    std::vector<uint8_t> disc_data;
};

#endif
