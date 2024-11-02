#include "TownHall.h"

TownHall::TownHall() : Service("Townhall")
{
}

void TownHall::payEmployees()
{
}

void TownHall::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *TownHall::clone()
{
    Cell* c = new TownHall();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
