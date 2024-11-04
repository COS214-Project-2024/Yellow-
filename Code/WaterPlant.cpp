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

void WaterPlant::createResource()
{
    City c = City::instanceCity();
    c.stuff.res->setWater(c.stuff.res->getWater() + 150); // + any number - 150 chosen at random
}