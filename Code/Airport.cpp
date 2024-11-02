#include "Airport.h"

Airport::Airport() : Service("Airport")
{
}

void Airport::setIcon()
{
}

void Airport::payEmployees()
{
}

void Airport::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *Airport::clone()
{
    Cell* c = new Airport();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
