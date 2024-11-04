#ifndef LABOUR_H
#define LABOUR_H

#include "Department.h"

class Labour : public Department {

    public:
        MaterialOrder* handle(Policies* policy);
};

#endif
