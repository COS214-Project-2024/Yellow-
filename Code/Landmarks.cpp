/**
* @class Landmarks
* @brief Class that represents a Landmark building
* @ingroup Factory
* @implements Residential factory
*
* The Landmarks class is a concrete factory participant of the Factory design pattern. It is used to create a landmark building.
*/
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

void Landmarks::createBuildingResource()
{
	City city = City::instanceCity();
	city.stuff.res->setMorale(city.stuff.res->getMorale() + (productionPerCell*coordinates.size()));
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

void Landmarks::addCitizenToBuilding(Citizen *newCitizen)
{
    if (currentNumberOfCitizens == maxCitizens)
        return;
    currentNumberOfCitizens++;
    dependentCitizens.push_back(newCitizen);
    newCitizen->setBusinessAddress(this);
}
