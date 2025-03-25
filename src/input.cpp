#include "input.hpp"

Input::Input() : buttonState(0xFFFF) {
}

void Input::update() {
    // TODO: Read actual input from keyboard, gamepad, or mapped controls
}

uint16_t Input::getButtonState() const {
    return buttonState;
}

void Input::setButtonState(uint16_t state) {
    buttonState = state;
}
