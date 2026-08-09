#ifndef CMDLINEARGS2PIPELINECONVERTER_H
#define CMDLINEARGS2PIPELINECONVERTER_H

#include <unordered_map>
#include <vector>

#include "../Pipeline/Pipeline.h"
#include "../Filters/headers/IFilter.h"
#include "../Filters/headers/FilterDescriptor.h"
#include "../FilterProducer/FilterProducer.h"


class CmdLineArgs2PipelineConverter {
public:
    Pipeline createPipeline(const std::vector<FilterDescriptor>& filterDescriptors);

    void addFilterProducer(const std::string& filterName, FilterProducers::FilterProducer);

    FilterProducers::FilterProducer getFilterProducer(const std::string& filterName);
private:
    std::unordered_map<std::string, FilterProducers::FilterProducer> _producers;
};



#endif //CMDLINEARGS2PIPELINECONVERTER_H
