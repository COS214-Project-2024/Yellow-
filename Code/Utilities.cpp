#include "Utilities.h"

Utilities::Utilities(string cellType) : Buildings(cellType) {}

void Utilities::acceptVisitor(Visitor *v)
{
    // TODO - implement Utilities::acceptVisitor
	throw "Not yet implemented";
}

void Utilities::taxBuilding()
{
    float tax = buildingMoney * City::instanceCity().stuff.res->getPropertyTaxRate();
    buildingMoney -= tax;
    float cityMoney = City::instanceCity().stuff.res->getBudget();
    City::instanceCity().stuff.res->setBudget(cityMoney + tax);
}

void Utilities::setIcon()
{
}

void Utilities::setProductionRate(int newRate)
{
    productionPerCell = newRate;
}

void Utilities::payEmployees()
{
}
