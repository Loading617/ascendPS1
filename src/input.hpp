#ifndef INPUT_HPP
#define INPUT_HPP

#include <cstdint>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_haptic.h>
#include <string>
#include <vector>

class Input {
public:
    Input();
    ~Input();

    void update();
    uint16_t getButtonState() const;
    void setButtonState(uint16_t state);

    void setVibration(float strength, uint32_t duration);
    void configureKey(SDL_Keycode key, uint16_t psButton);
    void saveKeyMappings(const std::string& filename);
    void loadKeyMappings(const std::string& filename);
    void loadProfile(const std::string& profileName);
    void saveProfile(const std::string& profileName);
    std::vector<std::string> getAvailableProfiles();

    void openRemapUI();

    int16_t getAnalogLX() const;
    int16_t getAnalogLY() const;
    int16_t getAnalogRX() const;
    int16_t getAnalogRY() const;
    void setAnalogSensitivity(float sensitivity);

private:
    uint16_t buttonState;
    int16_t analogLX, analogLY, analogRX, analogRY;
    float analogSensitivity;

    std::unordered_map<SDL_Keycode, uint16_t> keyMap;
    SDL_GameController* controller;
    SDL_Haptic* haptic;

    void initKeyMap();
    void handleKeyboard();
    void handleGamepad();
};

#endif
