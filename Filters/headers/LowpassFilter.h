#ifndef LOWPASSFILTER_H
#define LOWPASSFILTER_H
#include "IFilter.h"


class LowpassFilter : public IFilter{
public:
    LowpassFilter(size_t windowSize);

    ~LowpassFilter() override;

    State apply(Waveform &sound) override;

private:
    size_t _windowSize;
};



#endif //LOWPASSFILTER_H
