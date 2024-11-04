/**
* @class Forestry
* @brief Class that represents a Forestry building
* @ingroup Factory
* @implements Industrial factory
*
* The Forestry class is a concrete factory participant of the Factory design pattern. It is used to create a forestry building.
*/
#include "Forestry.h"

Forestry::Forestry() : Industrial("Forestry")
{
}

float Forestry::taxBuilding()
{
    // TODO - implement Forestry::taxBuilding
	throw "Not yet implemented";
}

void Forestry::createBuildingResource()
{
	if (&City::instanceCity() == nullptr)
		return;
	City c = City::instanceCity();
    c.stuff.res->setWood(c.stuff.res->getWood() + 90);
}
