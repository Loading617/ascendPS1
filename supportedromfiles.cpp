#include "supported rom files"

#define SUPPORTED_ROM_FILES "thrill_kill_uncensored.bin"
#define SUPPORTED_ROM_FILES "Tom Clancy's Rainbow Six (USA).chd"
#define SUPPORTED_ROM_FILES "alientrilogy.pbp"
#define SUPPORTED_ROM_FILES "tekken3.cue"
#define SUPPORTED_ROM_FILES "medalofhonor.ecm"
#define SUPPORTED_ROM_FILES "tenchu.mds"
#define SUPPORTED_ROM_FILES "shadowman.iso"
#define SUPPORTED_ROM_FILES "twistedmetal.img"

void load_rom(const char *rom_file) {
    // Load the ROM file into memory
    // ...
}

int main() {
    // Check if the provided ROM file is supported
    const char *supported_files = SUPPORTED_ROM_FILES;
    const char *extension = strrchr(rom_file, '.');
    if (extension && strstr(supported_files, extension + 1)) {
        load_rom(rom_file);
        // Start the game
    } else {
        std::cerr << "Error: Unsupported ROM file format." << std::endl;
        return 1;
    }