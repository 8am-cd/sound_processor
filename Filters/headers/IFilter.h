#ifndef IFILTER_H
#define IFILTER_H

#include "../../readAndWrite/headers/Waveform.h"

class IFilter {
public:
    enum class State{
        ok,
        badArgs
    };

    virtual ~IFilter() = default;
    virtual State apply(Waveform& sound) = 0;
protected:
    int16_t _minAmpl = -32768;
    int16_t _maxAmpl = 32767;
};


#endif //IFILTER_H
