#include "House.h"

House::House() : Residential("House")
{
}

void House::taxBuilding()
{
    // TODO - implement House::taxBuilding
	throw "Not yet implemented";
}

void House::setIcon()
{
}

void House::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *House::clone()
{
    Cell* c = new House();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
