#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Policies.h"
#include "MaterialOrder.h"
#include "RandomUtil.h"

class Department {

private:
	Department* successor;
    RandomUtil* randomVal;

public:
	virtual MaterialOrder* handle(Policies* policy) = 0;
    void setSuccessor(Department* newSuccessor);
};

#endif
