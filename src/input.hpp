#ifndef INPUT_HPP
#define INPUT_HPP

#include <cstdint>
#include <unordered_map>
#include <SDL2/SDL.h>

class Input {
public:
    Input();
    ~Input();

    void update();
    uint16_t getButtonState() const;
    void setButtonState(uint16_t state);

private:
    uint16_t buttonState;

    std::unordered_map<SDL_Keycode, uint16_t> keyMap;
    SDL_GameController* controller;

    void initKeyMap();
    void handleKeyboard();
    void handleGamepad();
};

#endif
