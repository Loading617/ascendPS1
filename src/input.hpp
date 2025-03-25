#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL2/SDL.h>
#include <map>
#include <string>

class Input {
public:
    Input();
    ~Input();

    void processEvent(const SDL_Event& event);
    uint16_t getButtonState() const;
    int8_t getAnalogLX() const;
    int8_t getAnalogLY() const;
    int8_t getAnalogRX() const;
    int8_t getAnalogRY() const;

    void openRemapUI();
    void saveKeyMappings(const std::string& filename);
    void loadKeyMappings(const std::string& filename);

private:
    void initKeyMap();

    uint16_t buttonState;
    int8_t analogLX, analogLY, analogRX, analogRY;
    float analogSensitivity;
    SDL_GameController* controller;
    SDL_Haptic* haptic;
    
    std::map<SDL_Keycode, uint16_t> keyMap;
    
    void saveProfile(const std::string& name);
    void loadProfile(const std::string& name);
};

#endif
