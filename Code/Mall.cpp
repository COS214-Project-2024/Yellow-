#include "Mall.h"

Mall::Mall() : Commercial("Mall")
{
}

void Mall::taxBuilding()
{
    // TODO - implement Mall::taxBuilding
	throw "Not yet implemented";
}

void Mall::setIcon()
{
}

void Mall::payEmployees()
{
}

void Mall::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *Mall::clone()
{
    Cell* c = new Mall();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
