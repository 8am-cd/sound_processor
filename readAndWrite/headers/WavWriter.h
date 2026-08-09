//
// Created by Иван Морозов on 12.06.2026.
//

#ifndef WAVWRITER_H
#define WAVWRITER_H

#include <fstream>

#include "Waveform.h"
#include "WavHeader.h"


class WavWriter : public WavFile {
public:
    WavWriter(const std::string& fileName);

    void write(const Waveform& block);

    ~WavWriter();
private:
    std::ofstream _file;
    uint32_t _samplesWritten;
};



#endif //WAVWRITER_H
