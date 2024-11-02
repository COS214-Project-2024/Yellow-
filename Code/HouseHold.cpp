#include "HouseHold.h"

HouseHold::HouseHold() : Residential("Household")
{
}

void HouseHold::taxBuilding()
{
}

void HouseHold::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *HouseHold::clone()
{
    Cell* c = new HouseHold();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
