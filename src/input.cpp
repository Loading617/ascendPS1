#include "input.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>

Input::Input() 
    : buttonState(0xFFFF), analogLX(0), analogLY(0), analogRX(0), analogRY(0),
      analogSensitivity(1.0f), controller(nullptr), haptic(nullptr) {
    
    if (SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
    } else {
        if (SDL_NumJoysticks() > 0) {
            controller = SDL_GameControllerOpen(0);
            if (controller) {
                if (SDL_GameControllerHasRumble(controller)) {
                    haptic = SDL_HapticOpenFromJoystick(SDL_GameControllerGetJoystick(controller));
                    if (haptic && SDL_HapticRumbleInit(haptic) < 0) {
                        std::cerr << "Haptic not supported: " << SDL_GetError() << std::endl;
                        SDL_HapticClose(haptic);
                        haptic = nullptr;
                    }
                }
            } else {
                std::cerr << "Could not open game controller: " << SDL_GetError() << std::endl;
            }
        }
    }
    initKeyMap();
    loadKeyMappings("keymap.cfg");
}

Input::~Input() {
    saveKeyMappings("keymap.cfg");
    if (haptic) SDL_HapticClose(haptic);
    if (controller) SDL_GameControllerClose(controller);
    SDL_Quit();
}

void Input::initKeyMap() {
    keyMap[SDLK_w] = 0x0001;
    keyMap[SDLK_s] = 0x0002;
    keyMap[SDLK_a] = 0x0004;
    keyMap[SDLK_d] = 0x0008;
    keyMap[SDLK_RETURN] = 0x0010;
    keyMap[SDLK_BACKSPACE] = 0x0020;
    keyMap[SDLK_SPACE] = 0x0040;
    keyMap[SDLK_LSHIFT] = 0x0080;
    keyMap[SDLK_k] = 0x0100;
    keyMap[SDLK_l] = 0x0200;
    keyMap[SDLK_q] = 0x0400;
    keyMap[SDLK_e] = 0x0800;
    keyMap[SDLK_z] = 0x1000;
    keyMap[SDLK_c] = 0x2000;
}

void Input::configureKey(SDL_Keycode key, uint16_t psButton) {
    keyMap[key] = psButton;
}

void Input::saveKeyMappings(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Failed to save key mappings!" << std::endl;
        return;
    }

    for (const auto& pair : keyMap) {
        file << pair.first << " " << pair.second << "\n";
    }

    file.close();
}

void Input::loadKeyMappings(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "No existing key mappings found, using defaults." << std::endl;
        return;
    }

    keyMap.clear();
    SDL_Keycode key;
    uint16_t psButton;
    
    while (file >> key >> psButton) {
        keyMap[key] = psButton;
    }

    file.close();
}

void Input::handleKeyboard() {
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    buttonState = 0xFFFF;

    for (const auto& pair : keyMap) {
        if (state[SDL_GetScancodeFromKey(pair.first)]) {
            buttonState &= ~pair.second;
        }
    }
}

void Input::handleGamepad() {
    if (!controller) return;

    buttonState = 0xFFFF;

    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP)) buttonState &= ~0x0001;
    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN)) buttonState &= ~0x0002;
    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT)) buttonState &= ~0x0004;
    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)) buttonState &= ~0x0008;
    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START)) buttonState &= ~0x0010;
    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK)) buttonState &= ~0x0020;
    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A)) buttonState &= ~0x0040;
    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X)) buttonState &= ~0x0080;
    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y)) buttonState &= ~0x0100;
    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B)) buttonState &= ~0x0200;
    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER)) buttonState &= ~0x0400;
    if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)) buttonState &= ~0x0800;

    analogLX = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX) * analogSensitivity;
    analogLY = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY) * analogSensitivity;
    analogRX = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTX) * analogSensitivity;
    analogRY = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTY) * analogSensitivity;
}

void Input::update() {
    SDL_PumpEvents();
    handleKeyboard();
    handleGamepad();
}

void Input::setAnalogSensitivity(float sensitivity) {
    analogSensitivity = sensitivity;
}
