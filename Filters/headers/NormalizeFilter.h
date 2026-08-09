//
// Created by Иван Морозов on 13.06.2026.
//

#ifndef NORMALIZE_H
#define NORMALIZE_H
#include "IFilter.h"


class NormalizeFilter : public IFilter{
public:
    NormalizeFilter(double peak);

    ~NormalizeFilter() override;

    State apply(Waveform &sound) override;

private:
    double _peak;
};



#endif //NORMALIZE_H
