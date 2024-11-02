#include "Museum.h"

void Museum::taxBuilding() {
	// TODO - implement Museum::taxBuilding
	throw "Not yet implemented";
}

Museum::Museum() : Landmarks("Museum")
{
}

void Museum::createBuildingResource()
{
	if (&City::instanceCity() == nullptr) 
		return;
	City city = City::instanceCity();
	city.stuff.res->setMorale(city.stuff.res->getMorale() + 1);
}

void Museum::payEmployees()
{
}

void Museum::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *Museum::clone()
{
    Cell* c = new Museum();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
