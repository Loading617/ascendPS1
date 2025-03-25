#ifndef INPUT_HPP
#define INPUT_HPP

#include <cstdint>

class Input {
public:
    Input();
    void update();
    uint16_t getButtonState() const;
    void setButtonState(uint16_t state);

private:
    uint16_t buttonState;
};

#endif
