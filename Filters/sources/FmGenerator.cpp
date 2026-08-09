#include "../headers/FmGenerator.h"

#include <cmath>

FmGenerator::FmGenerator(double ampl, double carrier, double modulation, double deviation, double duration) :
    _ampl(ampl), _carrier(carrier), _modulation(modulation), _deviation(deviation), _duration(duration) {
    bool expr1 = 0 <= _ampl && _ampl <= 1;
    bool expr2 = _carrier >= 0;
    bool expr3 = _modulation > 0;
    bool expr4 = 0 <= _deviation;
    bool expr5 = _duration >= 0;
    if (!expr1 || !expr2 || !expr3 || !expr4 || !expr5)
        throw std::runtime_error("Bad arguments for FmGenerator.");
}

IFilter::State FmGenerator::apply(Waveform& sound) {
    sound.resize(_duration * 44100 / 1000);

    for (int i = 0; i < sound.size(); ++i) {
        double t = i * 1.0 / 44100;
        double phase = 2 * M_PI * _carrier * t + (_deviation / _modulation) * sin(2 * M_PI * _modulation * t);
        sound[i] = std::clamp(static_cast<int>(_ampl * INT16_MAX * std::sin(phase)),
            INT16_MIN, INT16_MAX);
    }

    return State::ok;
}
