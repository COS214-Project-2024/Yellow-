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
    return c;
}
