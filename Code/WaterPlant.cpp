#include "WaterPlant.h"

WaterPlant::WaterPlant() : Utilities("WaterPlant")
{
}

void WaterPlant::createBuildingResource()
{
    City c = City::instanceCity();
    c.stuff.res->setWater(c.stuff.res->getWater() + productionPerCell*coordinates.size());
}

void WaterPlant::setIcon()
{
}

Cell *WaterPlant::clone()
{
    Cell* c = new WaterPlant();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
