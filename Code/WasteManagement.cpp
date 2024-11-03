#include "WasteManagement.h"

WasteManagement::WasteManagement() : Utilities("WasteManagement")
{
}

void WasteManagement::createBuildingResource()
{
    City c = City::instanceCity();
    c.stuff.res->setMorale(c.stuff.res->getMorale() + productionPerCell*coordinates.size()); // good hygiene improves morale
}

void WasteManagement::setIcon()
{
}

Cell *WasteManagement::clone()
{
    Cell* c = new WasteManagement();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
