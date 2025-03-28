#include "spu.hpp"
#include <iostream>
#include <cstring>

SPU::SPU() {
    reset();
}

SPU::~SPU() {
    
}

void SPU::reset() {
    std::memset(voices.data(), 0, sizeof(voices));
    audioBuffer.clear();
}

void SPU::writeRegister(uint32_t address, uint16_t value) {
    uint32_t voiceIndex = (address & 0xFF) / 8;
    
    if (voiceIndex < voices.size()) {
        switch (address % 8) {
            case 0x00: voices[voiceIndex].sampleAddress = value << 3; break;
            case 0x02: voices[voiceIndex].sampleRate = value; break;
            case 0x04: voices[voiceIndex].volumeLeft = value; break;
            case 0x06: voices[voiceIndex].volumeRight = value; break;
            default: break;
        }
    } else {
        std::cerr << "SPU: Write to unknown register " << std::hex << address << std::endl;
    }
}

uint16_t SPU::readRegister(uint32_t address) {
    uint32_t voiceIndex = (address & 0xFF) / 8;
    
    if (voiceIndex < voices.size()) {
        switch (address % 8) {
            case 0x00: return voices[voiceIndex].sampleAddress >> 3;
            case 0x02: return voices[voiceIndex].sampleRate;
            case 0x04: return voices[voiceIndex].volumeLeft;
            case 0x06: return voices[voiceIndex].volumeRight;
            default: return 0;
        }
    }
    
    std::cerr << "SPU: Read from unknown register " << std::hex << address << std::endl;
    return 0;
}

void SPU::processAudio() {
    audioBuffer.clear();

    for (auto& voice : voices) {
        if (voice.playing) {
            int16_t sample = 0;
            audioBuffer.push_back(sample);
        }
    }

    mixAudio();
}

void SPU::mixAudio() {
    for (auto& sample : audioBuffer) {
        sample = (sample * 2) / voices.size();
    }
}

void SPU::dmaTransfer() {
    
}
