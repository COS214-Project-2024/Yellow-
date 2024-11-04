#include "Commercial.h"
#include "Citizen.h"
#include "City.h"
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
    float wage = City::instanceCity().stuff.res->getWage();
    City::instanceCity().stuff.res->setBudget(City::instanceCity().stuff.res->getBudget() - 2 * wage * dependentCitizens.size());
    buildingMoney += 2 * wage * dependentCitizens.size();
    wage *= 2;
    wage = wage - wage * City::instanceCity().stuff.res->getPropertyTaxRate() - wage * City::instanceCity().stuff.res->getBusinessTaxRate();
    buildingMoney -= wage * dependentCitizens.size();
    for (Citizen* citizen : dependentCitizens) {
        citizen->setMoney(citizen->getMoney() + wage);
    }
}

void Commercial::addCitizenToBuilding(Citizen *newCitizen)
{
    if (currentNumberOfCitizens == maxCitizens)
        return;
    currentNumberOfCitizens++;
    dependentCitizens.push_back(newCitizen);
    newCitizen->setBusinessAddress(this);
}

void Commercial::createBuildingResource()
{
}
