//
// Created by Иван Морозов on 12.06.2026.
//

#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <vector>
#include <cstdint>


class Waveform {
public:
    Waveform() = default;

    explicit Waveform(std::vector<int16_t> samples, uint32_t sampleRate = 44100);

    int16_t& operator[](size_t ind);

    const int16_t& operator[](size_t ind) const;

    size_t secondsToIndex(double seconds) const;

    void resize(size_t size);

    size_t size() const;

    uint32_t getSampleRate() const;

    const int16_t* getData() const;
private:
    uint32_t _sampleRate = 44100;
    std::vector<int16_t> _samples;
};



#endif //WAVEFORM_H
