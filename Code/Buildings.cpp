/**
* @class Buildings
* @brief Buildings class
* @ingroup Composite
* @implements Section
*
* The Buildings class is a composite participant of the Composite design pattern. It is used to represent a building.
*/

#include "Buildings.h"

void Buildings::addSection(Cell* section){}

void Buildings::removeSection(int idx){}

Section* Buildings::getSection(int idx)
{
	return nullptr;
}

void Buildings::acceptVisitor(Visitor* v){}

void Buildings::setIcon()
{
}

void Buildings::setProductionRate(int newRate)
{
    productionPerCell = newRate;
}

Buildings::Buildings(string cellType) : Section(cellType)
{
    buildingMoney = 0;
}

float Buildings::getMoney()
{
    return buildingMoney;
}

void Buildings::setMoney(float newAmount)
{
    buildingMoney = newAmount;
}

int Buildings::getMaxCitizens()
{
    return this->maxCitizens;
}

Buildings::~Buildings()
{
	
}