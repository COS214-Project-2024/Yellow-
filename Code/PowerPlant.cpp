#include "PowerPlant.h"

PowerPlant::PowerPlant() : Utilities("PowerPlant")
{
}

void PowerPlant::createResource()
{
    City c = City::instanceCity();
    c.stuff.res->setPowerGrid(c.stuff.res->getPowerGrid() + 150); // + any number - 150 chosen at random
}
