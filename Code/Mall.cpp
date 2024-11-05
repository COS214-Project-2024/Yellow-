/**
* @class Mall
* @brief Class that represents a Mall building
* @ingroup Factory
* @implements Commercial factory
*
* The Mall class is a concrete factory participant of the Factory design pattern. It is used to create a mall building.
*/
#include "Mall.h"

Mall::Mall() : Commercial("Mall")
{
}

void Mall::setIcon()
{
}

Cell *Mall::clone()
{
    Cell* c = new Mall();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    setBaseForClone(c);
    return c;
}
