#ifndef AMENITIES_H
#define AMENITIES_H

#include "Department.h"

class Amenities : public Department {

    private:
        Department* successor;
        RandomUtil* randomVal;

    public:
        MaterialOrder* handle(Policies* policy);
};

#endif
