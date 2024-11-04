#include "PowerPlant.h"

PowerPlant::PowerPlant() : Utilities("PowerPlant")
{
}

void PowerPlant::createBuildingResource()
{
    City c = City::instanceCity();
    c.stuff.res->setPowerGrid(c.stuff.res->getPowerGrid() + 150); // + any number - 150 chosen at random
}

void PowerPlant::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *PowerPlant::clone()
{
    Cell* c = new PowerPlant();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
