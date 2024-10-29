#include "PowerPlant.h"

PowerPlant::PowerPlant()
{
    std::cout << "Power plant created" << std::endl;
}

void PowerPlant::createResource()
{
    City c = City::instanceCity();
    c.stuff.res->setEnergy(c.stuff.res->getEnergy() + 150); // + any number - 150 chosen at random
}
