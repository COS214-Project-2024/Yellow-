#include "Forestry.h"

Forestry::Forestry() : Industrial("Forestry")
{
}

void Forestry::createBuildingResource()
{
	if (&City::instanceCity() == nullptr)
		return;
	City c = City::instanceCity();
    c.stuff.res->setWood(c.stuff.res->getWood() + 90);
}

void Forestry::setIcon()
{
}

void Forestry::payEmployees()
{
}

void Forestry::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *Forestry::clone()
{
    Cell* c = new Forestry();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
