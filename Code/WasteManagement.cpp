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

void WasteManagement::createResource()
{
    City c = City::instanceCity();
    c.stuff.res->setMorale(c.stuff.res->getMorale() + 1); // good hygiene improves morale
}