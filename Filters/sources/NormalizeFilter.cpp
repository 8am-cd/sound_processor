//
// Created by Иван Морозов on 13.06.2026.
//

#include "../headers/NormalizeFilter.h"

NormalizeFilter::NormalizeFilter(double peak) : _peak(peak){
    if (!(_peak >= 0 && _peak <= 1))
        throw std::runtime_error("Argument for NormalizeFilter must be 0 <= [arg] <= 1");
}

NormalizeFilter::~NormalizeFilter() = default;

IFilter::State NormalizeFilter::apply(Waveform &sound) {
    int16_t currentPeak = INT16_MIN;
    for (size_t i = 0; i < sound.size(); ++i)
        currentPeak = std::max(currentPeak, static_cast<int16_t>(std::abs(sound[i])));

    if (currentPeak <= 0) return State::ok;

    double scale = _peak * _maxAmpl / currentPeak;
    for (size_t i = 0; i < sound.size(); ++i)
        sound[i] *= scale;

    return State::ok;
}

