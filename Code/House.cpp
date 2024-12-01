/**
* @class House
* @brief Class that represents a House building
* @ingroup Factory
* @implements Residential factory
*
* The House class is a concrete factory participant of the Factory design pattern. It is used to create a house building.
*/
#include "House.h"

House::House() : Residential("House")
{
    maxCitizens = 10;
}

void House::setIcon()
{
}

Cell *House::clone()
{
    Cell* c = new House();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    setBaseForClone(c);
    return c;
}
