#include "ArgsParser.h"

ArgsParser::ArgsParser() = default;

const std::string& ArgsParser::getInFileName() const {return _inFileName;}

const std::string& ArgsParser::getOutFileName() const {return _outFileName;}

const std::vector<FilterDescriptor>& ArgsParser::getFilterDescriptors() const {return _filterDescriptors;}


ArgsParser::Result ArgsParser::parse(int argc, char *argv[]) {
    if (argc == 1)
        return Result::noArgs;

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        if (arg == "-i") {
            if (i + 1 < argc)
                _inFileName = argv[++i];
            else
                return Result::badArgs;
        }
        else if (arg == "-o") {
            if (i + 1 < argc)
                _outFileName = argv[++i];
            else
                return Result::badArgs;
        }
        else if (arg == "-f") {
            FilterDescriptor filter;
            if (i + 1 < argc)
                filter._filterName = argv[++i];
            else
                return Result::badArgs;

            while (i + 1 < argc && (std::string(argv[i + 1]) != "-i" &&
                                    std::string(argv[i + 1]) != "-o" &&
                                    std::string(argv[i + 1]) != "-f"))
                filter._params.emplace_back(argv[++i]);

            _filterDescriptors.push_back(filter);
        }
        else {
            return Result::badArgs;
        }
    }

    if (_outFileName.empty())
        return Result::noOutput;



    return Result::ok;
}
