#pragma once

enum Button {
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_CROSS,
    BUTTON_CIRCLE,
    BUTTON_TRIANGLE,
    BUTTON_SQUARE,
    BUTTON_START,
    BUTTON_SELECT,
    BUTTON_L1,
    BUTTON_R1,
    BUTTON_L2,
    BUTTON_R2
};

class Controller {
public:
    void press(Button btn);
    void release(Button btn);
    bool isPressed(Button btn) const;
};
