#ifndef TIMESTRETCHFILTER_H
#define TIMESTRETCHFILTER_H
#include "IFilter.h"


class TimestretchFilter : public IFilter{
public:
    TimestretchFilter(double factor);

    ~TimestretchFilter() override;

    State apply(Waveform &sound) override;

private:
    double _factor;
};



#endif //TIMESTRETCHFILTER_H
