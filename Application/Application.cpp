

#include "Application.h"

#include <iostream>

#include "../FilterProducer/FilterProducer.h"
#include "../ArgsParser/ArgsParser.h"
#include "../readAndWrite/headers/WavReader.h"
#include "../readAndWrite/headers/WavWriter.h"

void Application::configure() {
    _cla2PipelineConverter.addFilterProducer("ampl",
                               FilterProducers::amplFilterCreator);
    _cla2PipelineConverter.addFilterProducer("normalize",
                               FilterProducers::normalizeFilterCreator);
    _cla2PipelineConverter.addFilterProducer("silence",
                               FilterProducers::silenceFilterCreator);
    _cla2PipelineConverter.addFilterProducer("timestretch",
                               FilterProducers::timestretchFilterCreator);
    _cla2PipelineConverter.addFilterProducer("lowpass",
                               FilterProducers::lowpassFilterCreator);
    _cla2PipelineConverter.addFilterProducer("generator",
                               FilterProducers::generatorCreator);
}

int Application::start(int argc, char *argv[]) {
    ArgsParser parser;
    ArgsParser::Result res = parser.parse(argc, argv);
    switch (res) {
        case ArgsParser::Result::noOutput:
            throw std::runtime_error("You did not provide output file.");
        case ArgsParser::Result::badArgs:
            throw std::runtime_error("You provided bad arguments.");
        case ArgsParser::Result::noArgs:
            std::cout << ("\t-i\t\tName of input file.\n"
                         "\t-o\t\tName of output file.\n"
                         "\t-f\t\tTo use filter.\n"
                         "\t  \t\t[NAME] [PARAMETRS]\n");
            return 0;
        default:
            break;
    }


    Pipeline pipeline = _cla2PipelineConverter.createPipeline(parser.getFilterDescriptors());

    const std::string inFileName = parser.getInFileName();
    const std::string outFileName = parser.getOutFileName();
    WavWriter wavWriter(outFileName);
    if (!inFileName.empty()) {
        WavReader wavReader(inFileName);
        Waveform sound = wavReader.read();
        pipeline.apply(sound);
        wavWriter.write(sound);
    }
    else {
        Waveform sound;
        pipeline.apply(sound);
        wavWriter.write(sound);
    }

    return 0;
}
