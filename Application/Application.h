#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Cmd2PipelineConverter/CmdLineArgs2PipelineConverter.h"

class Application {
public:
    int start(int argc, char* argv[]);

    void configure();
protected:
    CmdLineArgs2PipelineConverter _cla2PipelineConverter;
};




#endif //APPLICATION_H
