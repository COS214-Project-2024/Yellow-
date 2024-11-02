#include "Service.h"

Service::Service(string cellType) : Buildings(cellType)
{
}

void Service::taxBuilding()
{
	return;
}

void Service::createBuildingResource()
{
	City city = City::instanceCity();
	city.stuff.res->setMorale(city.stuff.res->getMorale() + 1);
}

void Service::acceptVisitor(Visitor* v) {
	v->visitBuilding(this);
}

void Service::setIcon()
{
}

void Service::payEmployees()
{
}
