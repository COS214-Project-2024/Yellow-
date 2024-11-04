#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "Policies.h"
#include "Department.h"

class Transport : public Department{

    public:
        MaterialOrder* handle(Policies* policy);

};

#endif
