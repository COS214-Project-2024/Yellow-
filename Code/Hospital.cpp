#include "Hospital.h"

Hospital::Hospital() : Service("Hospital")
{
}

void Hospital::setIcon()
{
}

void Hospital::payEmployees()
{
}

void Hospital::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *Hospital::clone()
{
    Cell* c = new Hospital();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
