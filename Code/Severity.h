/**
 * @file Severity.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * @brief Interface for the state pattern
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SEVERITY_H
#define SEVERITY_H

#include "People.h"
#include "Disatisfaction.h"
#include "Budget.h"

#include <iostream>
using namespace std;

class Severity {

    public:
        virtual ~Severity() {}
        virtual string getSeverity() = 0 ;
        virtual Severity* handle(bool increment) = 0;

};

#endif
