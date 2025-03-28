#ifndef SPU_HPP
#define SPU_HPP

#include <cstdint>
#include <array>
#include <vector>

class SPU {
public:
    SPU();
    ~SPU();

    void reset();
    void writeRegister(uint32_t address, uint16_t value);
    uint16_t readRegister(uint32_t address);
    void processAudio();

private:
    struct Voice {
        uint32_t sampleAddress;
        uint16_t sampleRate;
        uint16_t volumeLeft;
        uint16_t volumeRight;
        uint16_t adsr[4];
        uint16_t currentVolume;
        bool playing;
    };

    std::array<Voice, 24> voices;
    std::vector<int16_t> audioBuffer;
    
    void mixAudio();
    void dmaTransfer();
};

#endif
