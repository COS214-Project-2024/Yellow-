/**
* @class Government
* @brief Class that represents the government of the city
* @ingroup State, Strategy, Command, Chain of Responsibility
* @implements Department
*
* The Government class is a concrete handler participant of the Chain of Responsibility design pattern. It is used to handle the policies of the city.
*/
#ifndef CODE_INCREASEWAGES_H
#define CODE_INCREASEWAGES_H

#include "Strategy.h"

class IncreaseWages : public Strategy {

    public:
        Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour) override;

};


#endif //CODE_INCREASEWAGES_H
