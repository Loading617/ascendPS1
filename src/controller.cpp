#include "controller.hpp"

Controller::Controller() {
    button_state.set();
}

void Controller::press_button(uint16_t button) {
    button_state.reset(button);
}

void Controller::release_button(uint16_t button) {
    button_state.set(button);
}

uint16_t Controller::get_state() const {
    return button_state.to_ulong();
}
