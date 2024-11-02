#include "PoliceStation.h"

PoliceStation::PoliceStation() : Service("Police")
{
}

Cell *PoliceStation::clone()
{
    Cell* c = new PoliceStation();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
