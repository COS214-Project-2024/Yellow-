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
    return c;
}
