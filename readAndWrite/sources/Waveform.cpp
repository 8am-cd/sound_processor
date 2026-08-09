//
// Created by Иван Морозов on 12.06.2026.
//

#include "../headers/Waveform.h"

Waveform::Waveform(std::vector<int16_t> samples, uint32_t sampleRate) :
        _samples(std::move(samples)), _sampleRate(sampleRate) {}

int16_t &Waveform::operator[](size_t ind) {
    return _samples[ind];
}

const int16_t &Waveform::operator[](size_t ind) const {
    return _samples[ind];
}


size_t Waveform::secondsToIndex(double seconds) const {
    return seconds * _sampleRate;
}

void Waveform::resize(size_t size) {
    _samples.resize(size);
}

size_t Waveform::size() const {
    return _samples.size();
}


uint32_t Waveform::getSampleRate() const {
    return _sampleRate;
}

const int16_t* Waveform::getData() const {
    return _samples.data();
}




