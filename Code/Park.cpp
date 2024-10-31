#include "Park.h"

void Park::taxBuilding() {
	// TODO - implement Park::taxBuilding
	throw "Not yet implemented";
}

Park::Park() : Landmarks("Park")
{
}

void Park::createBuildingResource()
{
	if (&City::instanceCity() == nullptr) 
		return;
	City city = City::instanceCity();
	city.stuff.res->setMorale(city.stuff.res->getMorale() + 1);
}
