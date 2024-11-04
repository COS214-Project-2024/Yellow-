/**
* @class Apartment
* @brief Class that represents an Apartment building
* @ingroup Factory
* @implements Residential factory
*
* The Apartment class is a concrete factory participant of the Factory design pattern. It is used to create an apartment building.
*/
#include "Apartment.h"

Apartment::Apartment() : Residential("Apartment")
{
}

float Apartment::taxBuilding()
{
    // TODO - implement Apartment::taxBuilding
	throw "Not yet implemented";
}
