#include "../headers/WavReader.h"
#include "../headers/WavHeader.h"

#include <vector>
#include <stdexcept>
#include <string_view>

WavReader::WavReader(const std::string& fileName) :
                    _file(fileName, std::ios::binary), _samplesRead(0) {
    if (!_file.is_open())
        throw std::runtime_error("Could not open file: " + fileName);

    _file.read(reinterpret_cast<char*>(&_riffHeader), sizeof(_riffHeader));
    _file.read(reinterpret_cast<char*>(&_fmtHeader), sizeof(_fmtHeader));
    _file.read(reinterpret_cast<char*>(&_dataHeader), sizeof(_dataHeader));

    bool riffHeaderIsCorrect = std::string_view(_riffHeader.chunkID, 4) == "RIFF" &&
                               std::string_view(_riffHeader.waveID, 4) == "WAVE";
    bool fmtIsCorrect = std::string_view(_fmtHeader.chunkID, 4) == "fmt " &&
                        _fmtHeader.comprCode == 1 &&
                        _fmtHeader.sampleRate == 44100 &&
                        _fmtHeader.channelCount == 1 &&
                        _fmtHeader.bitsPerSample == 16;
    bool dataIsCorrect = std::string_view(_dataHeader.chunkID, 4) == "data";

    if (!(riffHeaderIsCorrect && fmtIsCorrect && dataIsCorrect))
        throw std::runtime_error("Incorrect input file: " + fileName);
}

Waveform WavReader::read() {
    std::vector<int16_t> samples(_dataHeader.size / 2);
    _file.read(reinterpret_cast<char*>(samples.data()), _dataHeader.size);

    Waveform block(std::move(samples), _fmtHeader.sampleRate);
    _samplesRead += _dataHeader.size / 2;

    return block;
}


bool WavReader::isEOF() const {
    return _file.eof();
}

WavReader::~WavReader() {
    _file.close();
}

