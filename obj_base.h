#include <string>

#ifndef MX_OBJECTBASE
#define MX_OBJECTBASE 1

struct ObjectiveBase {
    std::string name, type;
    ObjectiveBase(std::string objname = "NULL", std::string objtype = "NULL") {
        name = objname;
        type = objtype;
    }
};
#endif