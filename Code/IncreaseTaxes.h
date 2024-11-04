/**
 * @file IncreaseTaxes.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef INCREASETAXES_H
#define INCREASETAXES_H

#include "Strategy.h"

class IncreaseTaxes : public Strategy {

    public:
        Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour) override;

};

#endif
