/**
* @class Government
* @brief Class that represents the government of the city
* @ingroup State, Strategy, Command, Chain of Responsibility
* @implements Department
*
* The Government class is a concrete handler participant of the Chain of Responsibility design pattern. It is used to handle the policies of the city.
*/
#ifndef INCREASETAXES_H
#define INCREASETAXES_H

#include "Strategy.h"

class IncreaseTaxes : public Strategy {

    public:
        Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour) override;

};

#endif
