//
// Created by Иван Морозов on 12.06.2026.
//

#include "../headers/WavWriter.h"
#include "../headers/WavHeader.h"


WavWriter::WavWriter(const std::string &fileName) :
                    _file(fileName, std::ios::binary), _samplesWritten(0){
    if (!_file.is_open())
        throw std::runtime_error("Could not open file: " + fileName);
}

void WavWriter::write(const Waveform &sound) {
    _riffHeader.size = 36 + sound.size() * 2;
    _dataHeader.size = sound.size() * 2;
    _file.write(reinterpret_cast<char*>(&_riffHeader), sizeof(_riffHeader));
    _file.write(reinterpret_cast<char*>(&_fmtHeader), sizeof(_fmtHeader));
    _file.write(reinterpret_cast<char*>(&_dataHeader), sizeof(_dataHeader));

    _file.write(reinterpret_cast<const char*>(sound.getData()), sound.size() * sizeof(int16_t));
    _samplesWritten += sound.size();

}

WavWriter::~WavWriter() {
    _file.close();
}
