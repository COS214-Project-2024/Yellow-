/**
 * @file AddPublicTransport.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CODE_ADDPUBLICTRANSPORT_H
#define CODE_ADDPUBLICTRANSPORT_H

#include "Strategy.h"

class AddPublicTransport : public Strategy{
public:
    Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour) override;


};


#endif //CODE_ADDPUBLICTRANSPORT_H
