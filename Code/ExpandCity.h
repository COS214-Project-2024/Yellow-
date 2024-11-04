/**
 * @file ExpandCity.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef EXPANDCITY_H
#define EXPANDCITY_H

#include "Strategy.h"

class ExpandCity : public Strategy {

    public:
        Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour) override;

};

#endif
