/**
 * @file Labour.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef LABOUR_H
#define LABOUR_H

#include "Department.h"

class Labour : public Department {

    public:
        MaterialOrder* handle(Policies* policy);
};

#endif
