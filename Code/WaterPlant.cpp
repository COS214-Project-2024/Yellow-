/**
* @class WaterPlant
* @brief WaterPlant is a concrete participant of the Momento design pattern.
* @ingroup Factory
* @implements Utilities
*
* The WaterPlant class is a concrete participant of the Momento design pattern. It is used to create a water plant utility.
*/
#include "WaterPlant.h"

WaterPlant::WaterPlant() : Utilities("WaterPlant")
{
}

void WaterPlant::createBuildingResource()
{
    City c = City::instanceCity();
    c.stuff.res->setWaterGrid(c.stuff.res->getWaterGrid() + productionPerCell*coordinates.size());
}

void WaterPlant::setIcon()
{
}

Cell *WaterPlant::clone()
{
    Cell* c = new WaterPlant();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    setBaseForClone(c);
    return c;
}
