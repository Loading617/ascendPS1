#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include <string>

class Emulator {
public:
    Emulator();
    ~Emulator();
    void loadROM(const std::string& filepath);
    void run();
    void stop();

private:

    void initialize();
    void executeFrame();
};

#endif
