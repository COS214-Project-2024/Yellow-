/**
 * @file Transport.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "Policies.h"
#include "Department.h"

class Transport : public Department{

    private:
    Department* successor;
    RandomUtil* randomVal;

    public:
        MaterialOrder* handle(Policies* policy);

};

#endif
