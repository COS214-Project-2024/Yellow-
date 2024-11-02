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
