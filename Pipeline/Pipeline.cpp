#include "Pipeline.h"

Pipeline::~Pipeline() {
    for (auto filter : _filters)
        delete filter;
}

Pipeline::State Pipeline::apply(Waveform& sound) {
    for (auto filter : _filters)
        filter->apply(sound);
    return State::ok;
}

IFilter* Pipeline::addFilter(IFilter *filter) {
    _filters.push_back(filter);
    return filter;
}

size_t Pipeline::getFilterNumbers() const {
    return _filters.size();
}

IFilter *Pipeline::getFilter(size_t i) const {
    return _filters[i];
}


