//
// Created by Иван Морозов on 12.06.2026.
//

#ifndef WAVREADER_H
#define WAVREADER_H

#include <fstream>
#include <string>

#include "Waveform.h"
#include "WavHeader.h"

class WavReader : public WavFile {
public:
    WavReader() = default;

    WavReader (const std::string& fileName);

    Waveform read();

    bool isEOF() const;

    ~WavReader();
private:
    std::ifstream _file;
    uint32_t _samplesRead;
};



#endif //WAVREADER_H
