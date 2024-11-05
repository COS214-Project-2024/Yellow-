/**
 * @file Museum.cpp
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Museum.h"

Museum::Museum() : Landmarks("Museum")
{
}

void Museum::createBuildingResource()
{
	if (&City::instanceCity() == nullptr) 
		return;
	City city = City::instanceCity();
	city.stuff.res->setMorale(city.stuff.res->getMorale() + (productionPerCell*coordinates.size()));
}

Cell *Museum::clone()
{
    Cell* c = new Museum();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    setBaseForClone(c);
    return c;
}
