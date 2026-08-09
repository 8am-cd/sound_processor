#include "../headers/SinGenerator.h"

#include <cmath>

SinGenerator::SinGenerator(double frequencyHz, double durationMs) :
        _frequencyHz(frequencyHz), _durationMs(durationMs){
    if (_frequencyHz < 0 || durationMs < 0)
        throw std::runtime_error("Argument for SinGenerator must be >= 0");
}

IFilter::State SinGenerator::apply(Waveform& sound) {
    sound.resize(_durationMs * 44100 / 1000);

    for (int i = 0; i < sound.size(); ++i) {
        double t = i * 1.0 / 44100;
        sound[i] = std::clamp(static_cast<int>(INT16_MAX * std::sin(2 * M_PI * _frequencyHz * t)),
            INT16_MIN, INT16_MAX);
    }

    return State::ok;
}

