#include "CmdLineArgs2PipelineConverter.h"

Pipeline CmdLineArgs2PipelineConverter::createPipeline(const std::vector<FilterDescriptor> &filterDescriptors) {
    Pipeline pipeline;
    for (const auto& filterDescriptor : filterDescriptors) {
        FilterProducers::FilterProducer producer = getFilterProducer(filterDescriptor._filterName.c_str());
        if (producer) {
            IFilter* filter = producer(filterDescriptor);
            if (filter) {
                pipeline.addFilter(filter);
            }
        }
    }

    return pipeline;
}

void CmdLineArgs2PipelineConverter::addFilterProducer(const std::string& filterName,
    FilterProducers::FilterProducer producer) {
    _producers[filterName] = producer;
}

FilterProducers::FilterProducer CmdLineArgs2PipelineConverter::getFilterProducer(const std::string& filterName) {
    auto it = _producers.find(filterName);
    if (it != _producers.end())
        return it->second;

    return nullptr;
}


