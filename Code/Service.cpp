/**
* @class Service
* @brief Class that represents a Service building
* @ingroup Factory
* @implements Service factory
*
* The Service class is a concrete factory participant of the Factory design pattern. It is used to create a service building.
*/
#include "Service.h"
#include "Citizen.h"
Service::Service(string cellType) : Buildings(cellType)
{
}

void Service::taxBuilding()
{
    if (buildingMoney == 0)
        return;
	float tax = buildingMoney * City::instanceCity().stuff.res->getPropertyTaxRate();
    buildingMoney -= tax;
    float cityMoney = City::instanceCity().stuff.res->getBudget();
    City::instanceCity().stuff.res->setBudget(cityMoney + tax);}

void Service::createBuildingResource()
{
	City city = City::instanceCity();
	city.stuff.res->setMorale(city.stuff.res->getMorale() + 1);
}

void Service::acceptVisitor(Visitor* v) {
	v->visitBuilding(this);
}

void Service::setIcon()
{
}

void Service::payEmployees()
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

void Service::addCitizenToBuilding(Citizen *newCitizen)
{
    if (currentNumberOfCitizens == maxCitizens)
        return;
    currentNumberOfCitizens++;
    dependentCitizens.push_back(newCitizen);
    newCitizen->setBusinessAddress(this);
}
