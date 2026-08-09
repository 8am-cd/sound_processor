#ifndef FMGENERATOR_H
#define FMGENERATOR_H

#include "IFilter.h"

class FmGenerator : public IFilter{
public:
    FmGenerator(double ampl, double carrier, double modulation, double deviation, double duration);

    ~FmGenerator() override = default;

    State apply(Waveform &sound) override;

private:
    double _ampl;
    double _carrier;
    double _modulation;
    double _deviation;
    double _duration;
};



#endif //FMGENERATOR_H
