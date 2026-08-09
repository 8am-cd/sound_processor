cmake_minimum_required(VERSION 3.31)
project(sound_processor)

set(CMAKE_CXX_STANDARD 17)

add_executable(sound_processor main.cpp
        ArgsParser/ArgsParser.cpp
        ArgsParser/ArgsParser.h
        Filters/headers/FilterDescriptor.h
        readAndWrite/sources/Waveform.cpp
        readAndWrite/headers/Waveform.h
        readAndWrite/headers/WavHeader.h
        readAndWrite/sources/WavReader.cpp
        readAndWrite/headers/WavReader.h
        readAndWrite/sources/WavWriter.cpp
        readAndWrite/headers/WavWriter.h
        Filters/headers/IFilter.h
        Filters/sources/AmplFilter.cpp
        Filters/headers/AmplFilter.h
        Filters/sources/NormalizeFilter.cpp
        Filters/headers/NormalizeFilter.h
        Filters/sources/SilenceFilter.cpp
        Filters/headers/SilenceFilter.h
        Filters/sources/TimestretchFilter.cpp
        Filters/headers/TimestretchFilter.h
        Filters/sources/LowpassFilter.cpp
        Filters/headers/LowpassFilter.h
        Filters/sources/SinGenerator.cpp
        Filters/headers/SinGenerator.h
        Filters/sources/AmGenerator.cpp
        Filters/headers/AmGenerator.h
        Filters/sources/FmGenerator.cpp
        Filters/headers/FmGenerator.h
        Pipeline/Pipeline.cpp
        Pipeline/Pipeline.h
        Cmd2PipelineConverter/CmdLineArgs2PipelineConverter.cpp
        Cmd2PipelineConverter/CmdLineArgs2PipelineConverter.h
        FilterProducer/FilterProducer.cpp
        FilterProducer/FilterProducer.h
        Application/Application.cpp
        Application/Application.h
)
