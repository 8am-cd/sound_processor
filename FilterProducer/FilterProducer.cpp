#include "FilterProducer.h"

#include "../Filters/headers/AmGenerator.h"
#include "../Filters/headers/FmGenerator.h"
#include "../Filters/headers/SinGenerator.h"
#include "../Filters/headers/AmplFilter.h"
#include "../Filters/headers/LowpassFilter.h"
#include "../Filters/headers/NormalizeFilter.h"
#include "../Filters/headers/TimestretchFilter.h"
#include "../Filters/headers/SilenceFilter.h"


namespace FilterProducers {
    IFilter* amplFilterCreator(const FilterDescriptor& fd) {
        if (fd._filterName != "ampl")
            throw std::logic_error("Wrong fd for ampl filter producer.");

        if (fd._params.size() < 1)
            throw std::logic_error("Wrong params number for ampl filter producer.");

        try {
            double ampl = std::stod(fd._params[0]);

            IFilter* amplFilter = new AmplFilter(ampl);
            return amplFilter;
        }
        catch(std::invalid_argument& e)
        {
            throw std::logic_error("Error converting the 1st argument of ampl filter.");
        }
    }

    IFilter *lowpassFilterCreator(const FilterDescriptor &fd) {
        if (fd._filterName != "lowpass")
            throw std::logic_error("Wrong fd for lowpass filter producer.");

        if (fd._params.size() < 1)
            throw std::logic_error("Wrong params number for lowpass filter producer.");

        try {
            size_t windowSize = std::stoi(fd._params[0]);

            IFilter* lowpassFilter = new LowpassFilter(windowSize);
            return lowpassFilter;
        }
        catch(std::invalid_argument& e)
        {
            throw std::logic_error("Error converting the 1st argument of lowpass filter.");
        }
    }

    IFilter *normalizeFilterCreator(const FilterDescriptor &fd) {
        if (fd._filterName != "normalize")
            throw std::logic_error("Wrong fd for normalize filter producer.");

        if (fd._params.size() < 1)
            throw std::logic_error("Wrong params number for normalize filter producer.");

        try {
            double peak = std::stod(fd._params[0]);

            IFilter* normalizeFilter = new NormalizeFilter(peak);
            return normalizeFilter;
        }
        catch(std::invalid_argument& e)
        {
            throw std::logic_error("Error converting the 1st argument of normalize filter.");
        }
    }

    IFilter *silenceFilterCreator(const FilterDescriptor &fd) {
        if (fd._filterName != "silence")
            throw std::logic_error("Wrong fd for silence filter producer.");

        if (fd._params.size() != 3)
            throw std::logic_error("Wrong params number for silence filter producer.");

        try {
            std::string unit = fd._params[0];
            double start = std::stod(fd._params[1]);
            double end = std::stod(fd._params[2]);


            IFilter* silenceFilter = new SilenceFilter(unit, start, end);
            return silenceFilter;
        }
        catch(std::invalid_argument& e)
        {
            throw std::logic_error("Error converting arguments of silence filter.");
        }
    }

    IFilter *timestretchFilterCreator(const FilterDescriptor &fd) {
        if (fd._filterName != "timestretch")
            throw std::logic_error("Wrong fd for timestretch filter producer.");

        if (fd._params.size() < 1)
            throw std::logic_error("Wrong params number for timestretch filter producer.");

        try {
            double factor = std::stod(fd._params[0]);

            IFilter* timestretchFilter = new TimestretchFilter(factor);
            return timestretchFilter;
        }
        catch(std::invalid_argument& e)
        {
            throw std::logic_error("Error converting the 1st argument of timestretch filter.");
        }
    }

    IFilter *generatorCreator(const FilterDescriptor &fd) {
        if (fd._filterName != "generator")
            throw std::logic_error("Wrong fd for generator filter producer.");

        if (fd._params.size() < 1)
            throw std::logic_error("Wrong params number for generator filter producer.");

        std::string generatorName = fd._params[0];
        if (generatorName == "am") return amGeneratorCreator(fd);
        if (generatorName == "fm") return fmGeneratorCreator(fd);
        if (generatorName == "sin") return sinGeneratorCreator(fd);

        throw std::logic_error("Wrong name of generator filter producer.");
    }

    IFilter *amGeneratorCreator(const FilterDescriptor &fd) {
        if (fd._params.size() != 6)
            throw std::logic_error("Wrong params number for am generator filter producer.");

        try {
            double ampl = std::stod(fd._params[1]);
            double carrier = std::stod(fd._params[2]);
            double modulation = std::stod(fd._params[3]);
            double depth = std::stod(fd._params[4]);
            double duration = std::stod(fd._params[5]);

            IFilter* amGenerator = new AmGenerator(ampl, carrier, modulation, depth, duration);
            return amGenerator;
        }
        catch(std::invalid_argument& e)
        {
            throw std::logic_error("Error converting arguments of am generator filter.");
        }
    }

    IFilter *fmGeneratorCreator(const FilterDescriptor &fd) {
        if (fd._params.size() != 6)
            throw std::logic_error("Wrong params number for fm generator filter producer.");

        try {
            double ampl = std::stod(fd._params[1]);
            double carrier = std::stod(fd._params[2]);
            double modulation = std::stod(fd._params[3]);
            double deviation = std::stod(fd._params[4]);
            double duration = std::stod(fd._params[5]);

            IFilter* fmGenerator = new FmGenerator(ampl, carrier, modulation, deviation, duration);
            return fmGenerator;
        }
        catch(std::invalid_argument& e)
        {
            throw std::logic_error("Error converting arguments of fm generator filter.");
        }
    }

    IFilter *sinGeneratorCreator(const FilterDescriptor &fd) {
        if (fd._params.size() != 3)
            throw std::logic_error("Wrong params number for sin generator filter producer.");

        try {
            double frequency = std::stod(fd._params[1]);
            double duration = std::stod(fd._params[2]);

            IFilter* sinGenerator = new SinGenerator(frequency, duration);
            return sinGenerator;
        }
        catch(std::invalid_argument& e)
        {
            throw std::logic_error("Error converting arguments of sin generator filter.");
        }
    }
}