#include "../headers/TimestretchFilter.h"

#include <cmath>

TimestretchFilter::TimestretchFilter(double factor) : _factor(factor){
    if (_factor <= 0)
        throw std::runtime_error("Argument for TimestretchFilter must be > 0");
}

TimestretchFilter::~TimestretchFilter() = default;

IFilter::State TimestretchFilter::apply(Waveform &sound) {
    size_t newSize = std::round(sound.size() * _factor);
    std::vector<int16_t> newSamples(newSize);

    for (int i = 0; i < newSize; ++i) {
        double pos = i / _factor;
        auto l = static_cast<size_t>(pos);
        double frac = pos - l;

        if (i == newSize - 1)
            newSamples[i] = sound[l];
        else
            newSamples[i] = sound[l] * (1 - frac) + sound[l + 1] * frac;
    }

    sound = Waveform(std::move(newSamples));

    return State::ok;
}


