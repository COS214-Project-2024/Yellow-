/**
* @class Complex
* @brief Class that represents a Complex building
* @ingroup Factory
* @implements Residential factory
*
* The Complex class is a concrete factory participant of the Factory design pattern. It is used to create a complex building.
*/
#ifndef EXPANDCITY_H
#define EXPANDCITY_H

#include "Strategy.h"

class ExpandCity : public Strategy {

    public:
        Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour) override;

};

#endif
