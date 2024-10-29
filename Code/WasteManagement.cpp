#include "WasteManagement.h"

void WasteManagement::createResource()
{
    City c = City::instanceCity();
    c.stuff.res->setMorale(c.stuff.res->getMorale() + 1); // good hygiene improves morale
}