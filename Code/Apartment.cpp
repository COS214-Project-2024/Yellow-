#include "Apartment.h"

Apartment::Apartment() : Residential("Apartment")
{
}

void Apartment::taxBuilding()
{
}

void Apartment::setIcon()
{
}

void Apartment::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *Apartment::clone()
{
    Cell* c = new Apartment();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
