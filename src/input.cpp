#include "input.hpp"
#include <gtkmm.h>
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

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
    loadKeyMappings("profiles/default.cfg");
}

Input::~Input() {
    saveKeyMappings("profiles/default.cfg");
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

void Input::openRemapUI() {
    auto app = Gtk::Application::create();
    Gtk::Window window;
    window.set_title("Key Remapping");
    window.set_default_size(300, 400);

    Gtk::Box vbox(Gtk::ORIENTATION_VERTICAL, 10);
    window.add(vbox);

    for (auto& pair : keyMap) {
        Gtk::Button* button = Gtk::manage(new Gtk::Button("Press a key..."));
        vbox.pack_start(*button);

        button->signal_clicked().connect([this, button, &pair]() {
            SDL_Event event;
            button->set_label("Waiting for input...");
            while (true) {
                SDL_PollEvent(&event);
                if (event.type == SDL_KEYDOWN) {
                    keyMap[event.key.keysym.sym] = pair.second;
                    button->set_label(SDL_GetKeyName(event.key.keysym.sym));
                    break;
                }
            }
        });
    }

    Gtk::Button saveButton("Save Profile");
    saveButton.signal_clicked().connect([this]() {
        saveProfile("custom");
    });

    vbox.pack_start(saveButton);
    window.show_all_children();
    app->run(window);
}
