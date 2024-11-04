/**
* @class HouseHold
* @brief Class that represents a House building
* @ingroup Factory
* @implements Residential factory
*
* The HouseHold class is a concrete factory participant of the Factory design pattern. It is used to create a house building.
*/
#include "HouseHold.h"

HouseHold::HouseHold() : Residential("Household")
{
}

float HouseHold::taxBuilding()
{
    return 0.0;
}
