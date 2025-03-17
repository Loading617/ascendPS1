#include "cpu.hpp"
#include "memory.hpp"
#include "cdrom.hpp"
#include "controller.hpp"
#include <iostream>

int main() {
    Memory memory;
    CPU cpu(memory);
    CDROM cdrom;
    Controller controller;

    std::vector<uint8_t> bios = load_file("scph1001.bin");
    if (!bios.empty()) {
        memory.load_bios(bios);
    } else {
        std::cerr << "Failed to load BIOS!" << std::endl;
        return 1;
    }

    if (!cdrom.load_disc("game.bin")) {
        std::cerr << "No game loaded!" << std::endl;
        return 1;
    }

    controller.press_button(12);
    std::cout << "Controller State: " << std::hex << controller.get_state() << std::endl;

    for (int i = 0; i < 10; i++) {
        cpu.step();
    }

    return 0;
}
