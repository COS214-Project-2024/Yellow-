#include "Museum.h"

float Museum::taxBuilding() {
	// TODO - implement Museum::taxBuilding
	throw "Not yet implemented";
}

Museum::Museum()
{
	std::cout << "created Museum" << std::endl;
}

void Museum::createBuildingResource()
{
	if (&City::instanceCity() == nullptr) 
		return;
	City city = City::instanceCity();
	city.stuff.res->setMorale(city.stuff.res->getMorale() + 1);
}
