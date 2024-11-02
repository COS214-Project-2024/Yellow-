#include "WasteManagement.h"

WasteManagement::WasteManagement() : Utilities("WasteManagement")
{
}

void WasteManagement::createResource()
{
    City c = City::instanceCity();
    c.stuff.res->setMorale(c.stuff.res->getMorale() + 1); // good hygiene improves morale
}

void WasteManagement::setIcon()
{
}

void WasteManagement::payEmployees()
{
}

void WasteManagement::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *WasteManagement::clone()
{
    Cell* c = new WasteManagement();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
