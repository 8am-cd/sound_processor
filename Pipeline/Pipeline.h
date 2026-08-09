#ifndef PIPELINE_H
#define PIPELINE_H
#include <vector>

#include "../Filters/headers/IFilter.h"


class Pipeline {
public:
    enum class State {
        ok,
        badFilters
    };

    Pipeline() = default;
    Pipeline(const Pipeline&) = delete;
    Pipeline(Pipeline&&) = default;

    Pipeline& operator=(const Pipeline&) = delete;
    Pipeline& operator=(Pipeline&&) = default;
    ~Pipeline();

    State apply(Waveform& sound);

    IFilter* addFilter(IFilter* filter);
    size_t getFilterNumbers() const;
    IFilter* getFilter(size_t i) const;

protected:
    std::vector<IFilter*> _filters;
};



#endif //PIPELINE_H
