#include "Airport.h"

Airport::Airport() : Service("Airport")
{
}

void Airport::setIcon()
{
}

Cell *Airport::clone()
{
    Cell* c = new Airport();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
