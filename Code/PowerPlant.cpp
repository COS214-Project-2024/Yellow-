#include "PowerPlant.h"

PowerPlant::PowerPlant() : Utilities("PowerPlant")
{
}

void PowerPlant::createResource()
{
    City c = City::instanceCity();
    c.stuff.res->setEnergy(c.stuff.res->getEnergy() + 150); // + any number - 150 chosen at random
}
