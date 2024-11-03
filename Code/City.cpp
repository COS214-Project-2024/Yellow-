#include "City.h"
#include <typeinfo>
#include "Buildings.h"
City::City()
{
	Government::onlyInstance();
	buildings = vector<Buildings*>();
}

City &City::instanceCity()
{
    static City onlyInstance;
 	return onlyInstance;
}

void City::collectResources()
{
	//Loop over every building
	//Check if Industrial
	//If yes, add to the Resources
	for (Buildings* building : buildings) {
		building->createBuildingResource();
	}
	
}

void City::collectTaxes()
{
	//Loop over every citizen and Building
	//If Citizen, collect incomeTax and propretyTax
	//If building, collect businessTax and propretyTax (skip Service building)
	for (Buildings* building : buildings) {
		building->taxBuilding();
	}
}

void City::dealWithResources()
{

}

void City::dealWithPolicies()
{
	if (stuff.res->getPopulation() < 500)
	{
		Government::onlyInstance().handlePeople(false);
	}
	else
	{
		Government::onlyInstance().handlePeople(true);
	}
	
	if (stuff.res->getBudget() < 500)
	{
		Government::onlyInstance().handleBudget(false);
	}
	else
	{
		Government::onlyInstance().handleBudget(true);
	}

	if (stuff.res->getMorale() < 500)
	{
		Government::onlyInstance().handleMorale(false);
	}
	else
	{
		Government::onlyInstance().handleMorale(true);
	}
}

void City::addBuilding(Cell *newBuilding)
{
	Buildings* b = dynamic_cast<Buildings*>(newBuilding);
	if (b == nullptr) 
		return;
	buildings.push_back(b);
}

vector<Buildings *> City::getBuildings()
{
    return buildings;
}
