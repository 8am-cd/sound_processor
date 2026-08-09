//
// Created by Иван Морозов on 13.06.2026.
//

#ifndef AMPL_H
#define AMPL_H

#include "IFilter.h"



class AmplFilter : public IFilter {
public:
    AmplFilter(double ampl);

    ~AmplFilter() override;

    State apply(Waveform &sound) override;

private:
    double _ampl;
};



#endif //AMPL_H
