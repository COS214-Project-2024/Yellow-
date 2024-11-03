#include "Utilities.h"
#include "Citizen.h"
Utilities::Utilities(string cellType) : Buildings(cellType) 
{
    
}

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

void Utilities::addCitizenToBuilding(Citizen *newCitizen)
{
    if (currentNumberOfCitizens == maxCitizens)
        return;
    currentNumberOfCitizens++;
    dependentCitizens.push_back(newCitizen);
    newCitizen->setBusinessAddress(this);
}
