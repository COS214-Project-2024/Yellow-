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
