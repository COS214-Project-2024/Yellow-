/**
 * @file Amenities.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef AMENITIES_H
#define AMENITIES_H

#include "Department.h"

class Amenities : public Department {

    public:
        MaterialOrder* handle(Policies* policy);
};

#endif
