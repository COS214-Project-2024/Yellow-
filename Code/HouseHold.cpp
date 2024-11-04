#include "HouseHold.h"

HouseHold::HouseHold() : Residential("Household")
{
    maxCitizens = 10;
}

Cell *HouseHold::clone()
{
    Cell* c = new HouseHold();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
