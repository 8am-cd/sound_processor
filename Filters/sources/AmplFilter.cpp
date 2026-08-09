//
// Created by Иван Морозов on 13.06.2026.
//

#include "../headers/AmplFilter.h"


AmplFilter::AmplFilter(double ampl) : _ampl(ampl) {
    if (_ampl < 0)
        throw std::runtime_error("Argument for AmplFilter must be >= 0");
}


AmplFilter::~AmplFilter() = default;

IFilter::State AmplFilter::apply(Waveform &sound) {
    for (size_t i = 0; i < sound.size(); ++i) {
        sound[i] = std::clamp(sound[i] * _ampl,
                             static_cast<double>(_minAmpl),
                             static_cast<double>(_maxAmpl));
    }
    return State::ok;
}
