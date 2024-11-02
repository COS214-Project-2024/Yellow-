#include "HouseHold.h"

HouseHold::HouseHold() : Residential("Household")
{
}

Cell *HouseHold::clone()
{
    Cell* c = new HouseHold();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
