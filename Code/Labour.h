#ifndef LABOUR_H
#define LABOUR_H

#include "Department.h"

class Labour : public Department {

    private:
        Department* successor;
        RandomUtil* randomVal;

    public:
        MaterialOrder* handle(Policies* policy);
};

#endif
