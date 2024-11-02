#include "Buildings.h"

void Buildings::addSection(Section* section){}

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
}

void Buildings::createBuildingResource(){}

Buildings::Buildings(string cellType) : Section(cellType) {

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
