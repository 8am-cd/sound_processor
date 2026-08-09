#ifndef AMGENERATOR_H
#define AMGENERATOR_H

#include "IFilter.h"


class AmGenerator : public IFilter{
public:
    AmGenerator(double ampl, double carrier, double modulation, double depth, double duration);

    ~AmGenerator() override = default;

    State apply(Waveform &sound) override;
private:
    double _ampl;
    double _carrier;
    double _modulation;
    double _depth;
    double _duration;
};



#endif //AMGENERATOR_H
