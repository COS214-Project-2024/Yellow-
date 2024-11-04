#ifndef AMENITIES_H
#define AMENITIES_H

#include "Department.h"

class Amenities : public Department {

    public:
        MaterialOrder* handle(Policies* policy);
};

#endif
