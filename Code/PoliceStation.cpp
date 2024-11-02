#include "PoliceStation.h"

PoliceStation::PoliceStation() : Service("Police")
{
}

void PoliceStation::payEmployees()
{
}

void PoliceStation::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *PoliceStation::clone()
{
    Cell* c = new PoliceStation();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
