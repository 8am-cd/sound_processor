#include "../headers/SilenceFilter.h"

#include <utility>

SilenceFilter::SilenceFilter(std::string unit, double start, double end) :
    _unit(std::move(unit)), _start(start), _end(end){
    if (_start < 0 || _end < _start || _unit != "sec" && _unit != "ms")
        throw std::runtime_error("Bad arguments on SilenceFilter");

    if (_unit == "ms") {
        _start /= 1000;
        _end /= 1000;
    }
}

SilenceFilter::~SilenceFilter() = default;

IFilter::State SilenceFilter::apply(Waveform &sound) {
    size_t startSample = sound.secondsToIndex(_start);
    size_t endSample = sound.secondsToIndex(_end);
    std::vector<int16_t> samples(endSample - startSample + sound.size());

    for (size_t i = 0; i < startSample; ++i)
        samples[i] = sound[i];
    for (size_t i = startSample; i < endSample; ++i)
        samples[i] = 0;
    for (size_t i = endSample; i < samples.size(); ++i)
        samples[i] = sound[i - endSample + startSample];

    sound = Waveform(std::move(samples));

    return State::ok;
}
