/**
* @class Residential
* @brief Class that represents a Residential building
* @ingroup Factory
* @implements Residential factory
*
* The Residential class is a concrete factory participant of the Factory design pattern. It is used to create a residential building.
*/
#include "Residential.h"
#include "Citizen.h"
Residential::Residential(string cellType) : Buildings(cellType) {}

void Residential::taxBuilding()
{
    if (buildingMoney == 0)
        return;
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
void Residential::addCitizenToBuilding(Citizen *newCitizen)
{
    if (currentNumberOfCitizens == maxCitizens)
        return;
    currentNumberOfCitizens++;
    dependentCitizens.push_back(newCitizen);
    newCitizen->setAccommodation(dynamic_cast<Residential*>(this));
}
void Residential::createBuildingResource()
{
}