#include "Park.h"

Park::Park() : Landmarks("Park")
{
}

void Park::createBuildingResource()
{
	if (&City::instanceCity() == nullptr) 
		return;
	City city = City::instanceCity();
	city.stuff.res->setMorale(city.stuff.res->getMorale() + productionPerCell*coordinates.size());
}

Cell *Park::clone()
{
    Cell* c = new Park();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
