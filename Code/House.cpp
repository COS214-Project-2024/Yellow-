/**
* @class House
* @brief Class that represents a House building
* @ingroup Factory
* @implements Residential factory
*
* The House class is a concrete factory participant of the Factory design pattern. It is used to create a house building.
*/
#include "House.h"

House::House() : Residential("House")
{
}

float House::taxBuilding()
{
    // TODO - implement House::taxBuilding
	throw "Not yet implemented";
}
