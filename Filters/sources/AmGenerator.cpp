#include "../headers/AmGenerator.h"

#include <cmath>

AmGenerator::AmGenerator(double ampl, double carrier, double modulation, double depth, double duration) :
    _ampl(ampl), _carrier(carrier), _modulation(modulation), _depth(depth), _duration(duration) {
    bool expr1 = 0 <= _ampl && _ampl <= 1;
    bool expr2 = _carrier >= 0;
    bool expr3 = _modulation >= 0;
    bool expr4 = 0 <= _depth && _depth <= 1;
    bool expr5 = _duration >= 0;
    if (!expr1 || !expr2 || !expr3 || !expr4 || !expr5)
        throw std::runtime_error("Bad arguments for AmGenerator.");
}

IFilter::State AmGenerator::apply(Waveform &sound) {
    sound.resize(_duration * 44100 / 1000);

    for (int i = 0; i < sound.size(); ++i) {
        double t = i * 1.0 / 44100;
        double envelope = 1 + _depth * std::sin(2 * M_PI * _modulation * t);
        double carrier = std::sin(2 * M_PI * _carrier * t);
        sound[i] = std::clamp(static_cast<int>(_ampl * INT16_MAX * envelope * carrier),
            INT16_MIN, INT16_MAX);
    }

    return State::ok;
}
