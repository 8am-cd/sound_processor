#include "../headers/LowpassFilter.h"

LowpassFilter::LowpassFilter(size_t windowSize) : _windowSize(windowSize){
    if (windowSize % 2 == 0 || windowSize < 1)
        throw std::runtime_error("Argument for LowpassFilter must be odd and >= 1");
}

LowpassFilter::~LowpassFilter() = default;

IFilter::State LowpassFilter::apply(Waveform &sound) {
    if (sound.size() == 0)
        return State::ok;

    std::vector<int16_t> newSamples(sound.size());

    int64_t currentSum = 0;
    int offset = (_windowSize - 1) / 2;

    for (int i = 0; i < sound.size() && i <= offset; ++i) {
        currentSum += sound[i];
    }
    currentSum += offset * sound[0];

    for (int i = 0; i < newSamples.size(); ++i) {
        newSamples[i] = currentSum * 1.0 / _windowSize;

        currentSum -= newSamples[std::max(0, i - offset - 1)];
        currentSum += newSamples[std::min(static_cast<int>(newSamples.size()) - 1, i + offset + 1)];
    }

    sound = Waveform(std::move(newSamples));

    return State::ok;
}


