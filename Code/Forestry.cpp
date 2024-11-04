/**
* @class Forestry
* @brief Class that represents a Forestry building
* @ingroup Factory
* @implements Industrial factory
*
* The Forestry class is a concrete factory participant of the Factory design pattern. It is used to create a forestry building.
*/
#include "Forestry.h"
#include "City.h"
Forestry::Forestry() : Industrial("Forestry")
{
}

void Forestry::createBuildingResource()
{
	if (&City::instanceCity() == nullptr)
		return;
	City c = City::instanceCity();
    c.stuff.res->setWood(c.stuff.res->getWood() + productionPerCell*coordinates.size());
}

void Forestry::setIcon()
{
}

Cell *Forestry::clone()
{
    Cell* c = new Forestry();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
