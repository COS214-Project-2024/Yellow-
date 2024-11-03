#include "Industrial.h"
#include "Citizen.h"
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

void Industrial::addCitizenToBuilding(Citizen *newCitizen)
{
    if (currentNumberOfCitizens == maxCitizens)
        return;
    currentNumberOfCitizens++;
    dependentCitizens.push_back(newCitizen);
    newCitizen->setBusinessAddress(this);
}

void Industrial::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}

void Industrial::setIcon()
{
}
