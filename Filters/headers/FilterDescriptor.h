#ifndef FILTERDESCRIPTOR_H
#define FILTERDESCRIPTOR_H

#include <vector>
#include <string>

struct FilterDescriptor {
    std::string _filterName;
    std::vector<std::string> _params;
};

#endif //FILTERDESCRIPTOR_H
