#include "Residential.h"

Residential::Residential(string cellType) : Buildings(cellType) {}

void Residential::taxBuilding()
{
    float tax = buildingMoney * City::instanceCity().stuff.res->getPropertyTaxRate() + buildingMoney * City::instanceCity().stuff.res->getIncomeTaxRate();
    buildingMoney -= tax;
    float cityMoney = City::instanceCity().stuff.res->getBudget();
    City::instanceCity().stuff.res->setBudget(cityMoney + tax);
}

void Residential::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}

void Residential::setIcon()
{
}

void Residential::payEmployees()
{
    // do nothing
}