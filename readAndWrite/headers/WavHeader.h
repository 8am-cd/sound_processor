#ifndef WAVHEADER_H
#define WAVHEADER_H

#include <cstdint>

struct __attribute__((packed)) RiffHeader
{
    char chunkID[4] = {'R', 'I', 'F', 'F'};
    uint32_t size = 36;
    char waveID[4] = {'W', 'A', 'V', 'E'};
};

struct __attribute__((packed)) FmtHeader
{
    char chunkID[4] = {'f', 'm', 't', ' '};
    uint32_t size = 16;
    uint16_t comprCode = 1;
    uint16_t channelCount = 1;
    uint32_t sampleRate = 44100;
    uint32_t bytesPerSecond = 88200;
    uint16_t blockAlign = 2;
    uint16_t bitsPerSample = 16;
};

struct __attribute__((packed)) DataHeader
{
    char chunkID[4] = {'d', 'a', 't', 'a'};
    uint32_t size = 0;
};


class WavFile {

protected:
    RiffHeader _riffHeader{};
    FmtHeader _fmtHeader{};
    DataHeader _dataHeader{};
};


#endif //WAVHEADER_H
