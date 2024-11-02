#include "Industrial.h"

void Industrial::setProductionRate(int newRate)
{
    productionPerCell = newRate;
}

Industrial::Industrial(string cellType) : Buildings(cellType)
{
    productionPerCell = 0;
}

void Industrial::taxBuilding()
{
    float tax = buildingMoney * City::instanceCity().stuff.res->getPropertyTaxRate();
    buildingMoney -= tax;
    float cityMoney = City::instanceCity().stuff.res->getBudget();
    City::instanceCity().stuff.res->setBudget(cityMoney + tax);
}

void Industrial::payEmployees()
{
}

void Industrial::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}

void Industrial::setIcon()
{
}
