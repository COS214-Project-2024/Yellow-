#ifndef FINANCES_H
#define FINANCES_H

#include "Department.h"

class Finances : public Department {

    public:
        MaterialOrder* handle(Policies* policy);

};

#endif
