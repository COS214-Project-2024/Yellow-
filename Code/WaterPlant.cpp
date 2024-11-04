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
    return c;
}
