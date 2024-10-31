#include "WaterPlant.h"

WaterPlant::WaterPlant() : Utilities("WaterPlant")
{
}

void WaterPlant::createResource()
{
    City c = City::instanceCity();
    c.stuff.res->setWaterGrid(c.stuff.res->getWaterGrid() + 150); // + any number - 150 chosen at random
}