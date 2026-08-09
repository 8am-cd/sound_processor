#ifndef SILENCE_H
#define SILENCE_H
#include "IFilter.h"

#include <string>

class SilenceFilter : public IFilter{
public:
    SilenceFilter(std::string unit, double start, double end);

    ~SilenceFilter() override;

    State apply(Waveform &sound) override;

private:
    std::string _unit;
    double _start;
    double _end;
};



#endif //SILENCE_H
