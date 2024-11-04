#include "Buildings.h"

void Buildings::addSection(Cell* section){}

void Buildings::removeSection(int idx){}

Cell* Buildings::getSection(int idx)
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