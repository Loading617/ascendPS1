#ifndef INPUT_HPP
#define INPUT_HPP

#include <cstdint>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_haptic.h>

class Input {
public:
    Input();
    ~Input();

    void update();
    uint16_t getButtonState() const;
    void setButtonState(uint16_t state);

    void setVibration(float strength, uint32_t duration);
    void configureKey(SDL_Keycode key, uint16_t psButton);

    int16_t getAnalogLX() const;
    int16_t getAnalogLY() const;
    int16_t getAnalogRX() const;
    int16_t getAnalogRY() const;

private:
    uint16_t buttonState;
    int16_t analogLX, analogLY, analogRX, analogRY;

    std::unordered_map<SDL_Keycode, uint16_t> keyMap;
    SDL_GameController* controller;
    SDL_Haptic* haptic;

    void initKeyMap();
    void handleKeyboard();
    void handleGamepad();
};

#endif
