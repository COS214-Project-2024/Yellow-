/**
* @class SteelFactory
* @brief Class that represents a Steel Factory building
* @ingroup Factory
* @implements Industrial factory
*
* The SteelFactory class is a concrete factory participant of the Factory design pattern. It is used to create a steel factory building.
*/
#include "SteelFactory.h"

SteelFactory::SteelFactory() : Industrial("SteelFactory")
{
}

void SteelFactory::createBuildingResource()
{
	if (&City::instanceCity() == nullptr)
        return;
    
    City c = City::instanceCity();
    int oldAmount = c.stuff.res->getSteel();
    c.stuff.res->setSteel(oldAmount + productionPerCell*coordinates.size()); // + any number - 90 chosen at random
}

Cell *SteelFactory::clone()
{
    Cell* c = new SteelFactory();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
