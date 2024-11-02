#include "Shop.h"

Shop::Shop() : Commercial("Shop")
{
}

void Shop::taxBuilding()
{
    // TODO - implement Shop::taxBuilding
	throw "Not yet implemented";
}

void Shop::payEmployees()
{
}

void Shop::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *Shop::clone()
{
    Cell* c = new Shop();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
