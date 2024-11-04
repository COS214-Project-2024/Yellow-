/**
* @class Park
* @brief Class that represents a Park building
* @ingroup Factory
* @implements Landmarks factory
*
* The Park class is a concrete factory participant of the Factory design pattern. It is used to create a park building.
*/
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
