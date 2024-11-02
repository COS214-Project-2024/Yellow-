#include "Apartment.h"

Apartment::Apartment() : Residential("Apartment")
{
}

void Apartment::setIcon()
{
}

Cell *Apartment::clone()
{
    Cell* c = new Apartment();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}