/**
* @class PowerPlant
* @brief Class that represents a PowerPlant building
* @ingroup Factory
* @implements Utilities factory
*
* The PowerPlant class is a concrete factory participant of the Factory design pattern. It is used to create a power plant building.
*/
#include "PowerPlant.h"

PowerPlant::PowerPlant() : Utilities("PowerPlant")
{
}

void PowerPlant::createResource()
{
    City c = City::instanceCity();
    c.stuff.res->setEnergy(c.stuff.res->getEnergy() + 150); // + any number - 150 chosen at random
}
