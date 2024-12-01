/**
* @class WasteManagement
* @brief WasteManagement is a concrete participant of the Momento design pattern.
* @ingroup Factory 
* @implements Utilities
*
* The WasteManagement class is a concrete participant of the Momento design pattern. It is used to create a waste management utility.
*/
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
    setBaseForClone(c);
    return c;
}
