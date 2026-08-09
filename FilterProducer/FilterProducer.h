#ifndef FILTERPRODUCER_H
#define FILTERPRODUCER_H

#include "../Filters/headers/IFilter.h"
#include "../Filters/headers/FilterDescriptor.h"

namespace FilterProducers {
    using FilterProducer = IFilter* (*) (const FilterDescriptor&);

    IFilter* amplFilterCreator(const FilterDescriptor& fd);

    IFilter* lowpassFilterCreator(const FilterDescriptor& fd);

    IFilter* normalizeFilterCreator(const FilterDescriptor& fd);

    IFilter* silenceFilterCreator(const FilterDescriptor& fd);

    IFilter* timestretchFilterCreator(const FilterDescriptor& fd);

    IFilter* generatorCreator(const FilterDescriptor& fd);

    IFilter* amGeneratorCreator(const FilterDescriptor& fd);

    IFilter* fmGeneratorCreator(const FilterDescriptor& fd);

    IFilter* sinGeneratorCreator(const FilterDescriptor& fd);
}

#endif //FILTERPRODUCER_H
