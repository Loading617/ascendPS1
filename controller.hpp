#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <cstdint>
#include <bitset>

class Controller {
public:
    Controller();
    void press_button(uint16_t button);
    void release_button(uint16_t button);
    uint16_t get_state() const;

private:
    std::bitset<16> button_state;
};

#endif
