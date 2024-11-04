/**
* @class Shop
* @brief Class that represents a Shop building
* @ingroup Factory
* @implements Commercial factory
*
* The Shop class is a concrete factory participant of the Factory design pattern. It is used to create a shop building.
*/
#include "Shop.h"

Shop::Shop() : Commercial("Shop")
{
}

Cell *Shop::clone()
{
    Cell* c = new Shop();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
