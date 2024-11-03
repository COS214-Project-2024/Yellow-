#include "TownHall.h"

TownHall::TownHall() : Service("Townhall")
{
}

Cell *TownHall::clone()
{
    Cell* c = new TownHall();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
