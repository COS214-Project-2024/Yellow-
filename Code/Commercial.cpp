#include "Commercial.h"

Commercial::Commercial(string cellType) : Buildings(cellType) {}

void Commercial::taxBuilding()
{
    float tax = buildingMoney * City::instanceCity().stuff.res->getPropertyTaxRate() + buildingMoney * City::instanceCity().stuff.res->getBusinessTaxRate();
    buildingMoney -= tax;
    float cityMoney = City::instanceCity().stuff.res->getBudget();
    City::instanceCity().stuff.res->setBudget(cityMoney + tax);
}

void Commercial::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}

void Commercial::setIcon()
{
}

void Commercial::payEmployees()
{
    if (dependentCitizens.size() == 0)
        return;
    
}
