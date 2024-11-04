/**
* @class Service
* @brief Class that represents a Service building
* @ingroup Factory
* @implements Service factory
*
* The Service class is a concrete factory participant of the Factory design pattern. It is used to create a service building.
*/
#include "Service.h"

Service::Service(string cellType) : Buildings(cellType)
{
}

float Service::taxBuilding()
{
	return 0.0f;
}

void Service::createBuildingResource()
{
	City city = City::instanceCity();
	city.stuff.res->setMorale(city.stuff.res->getMorale() + 1);
}

void Service::acceptVisitor(Visitor* v) {
	v->visitBuilding(this);
}
