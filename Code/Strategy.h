/**
 * @file Strategy.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef STRATEGY_H
#define STRATEGY_H

#include "Policies.h"

#include <iostream>
using namespace std;

class Strategy {
private:

    public:
    virtual Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour);
};

#endif
