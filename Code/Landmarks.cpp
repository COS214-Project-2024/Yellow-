#include "Landmarks.h"
#include "Citizen.h"
Landmarks::Landmarks(string cellType) : Buildings(cellType) {}

void Landmarks::taxBuilding()
{
    float tax = buildingMoney * City::instanceCity().stuff.res->getPropertyTaxRate();
    buildingMoney -= tax;
    float cityMoney = City::instanceCity().stuff.res->getBudget();
    City::instanceCity().stuff.res->setBudget(cityMoney + tax);
}

void Landmarks::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}

void Landmarks::setIcon()
{
}

void Landmarks::payEmployees()
{
    if (dependentCitizens.size() == 0) 
        return;
        
    float wage = City::instanceCity().stuff.res->getWage();
    City::instanceCity().stuff.res->setBudget(wage * dependentCitizens.size());
    buildingMoney += wage * City::instanceCity().stuff.res->getPropertyTaxRate() * dependentCitizens.size();
    wage = wage - wage * City::instanceCity().stuff.res->getPropertyTaxRate();
    buildingMoney -= wage * dependentCitizens.size();
    for (Citizen* citizen : dependentCitizens) {
        citizen->setMoney(citizen->getMoney() + wage);
    }
}