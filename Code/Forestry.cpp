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
