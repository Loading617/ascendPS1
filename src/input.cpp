#include "input.hpp"
#include <SDL2/SDL.h>
#include <iostream>

Input::Input() : buttonState(0xFFFF), controller(nullptr) {
    if (SDL_Init(SDL_INIT_GAMECONTROLLER) < 0) {
        std::cerr << "Failed to initialize SDL GameController: " << SDL_GetError() << std::endl;
    } else {
        if (SDL_NumJoysticks() > 0) {
            controller = SDL_GameControllerOpen(0);
            if (!controller) {
                std::cerr << "Could not open game controller: " << SDL_GetError() << std::endl;
            }
        }
    }
    initKeyMap();
}

Input::~Input() {
    if (controller) {
        SDL_GameControllerClose(controller);
    }
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
}

void Input::update() {
    SDL_PumpEvents();
    handleKeyboard();
    handleGamepad();
}

uint16_t Input::getButtonState() const {
    return buttonState;
}

void Input::setButtonState(uint16_t state) {
    buttonState = state;
}
