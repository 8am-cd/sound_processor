#ifndef SINGENERATOR_H
#define SINGENERATOR_H

#include "IFilter.h"


class SinGenerator : public IFilter{
public:
    SinGenerator(double frequencyHz, double durationMs);

    ~SinGenerator() override = default;

    State apply(Waveform &sound) override;
private:
    double _frequencyHz;
    double _durationMs;
};



#endif //SINGENERATOR_H
