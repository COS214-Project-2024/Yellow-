/**
* @class Finances
* @brief Finances class
* @ingroup Budget
* @implements Department
*
* The Finances class is a concrete handler participant of the Chain of Responsibility design pattern. It is used to handle the IncreaseTaxes policy.
*/
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
