/**
* @class Strategy
* @brief A class used to implement a policy
* @ingroup Strategy
* @implements Strategy
*
* Interface for the strategy pattern. 
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
