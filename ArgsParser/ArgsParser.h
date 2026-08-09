#ifndef ARGSPARSER_H
#define ARGSPARSER_H

#include <vector>

#include "../Filters/headers/FilterDescriptor.h"


class ArgsParser {
public:
    enum class Result {
        ok,
        noArgs,
        badArgs,
        noOutput
    };

    ArgsParser();

    Result parse(int argc, char* argv[]);

    const std::string& getInFileName() const;

    const std::string& getOutFileName() const;

    const std::vector<FilterDescriptor>& getFilterDescriptors() const;

private:
    std::string _inFileName;
    std::string _outFileName;
    std::vector<FilterDescriptor> _filterDescriptors;
};



#endif //ARGSPARSER_H
