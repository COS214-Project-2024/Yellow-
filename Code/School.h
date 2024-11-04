#ifndef SCHOOL_H
#define SCHOOL_H
#include "Service.h"
class School : public Service {
    public:
        School();
        Cell* clone();
};

#endif