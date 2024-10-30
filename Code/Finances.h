#ifndef FINANCES_H
#define FINANCES_H

#include "Department.h"

class Finances : public Department {

    private:
        Department* successor;
        RandomUtil* randomVal;

    public:
        MaterialOrder* handle(Policies* policy);

};

#endif
