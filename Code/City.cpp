#include "City.h"

City::City(Section* head)
{
	Government::onlyInstance();
	stuff.head = head;
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
	
	const auto& building = stuff.head->getChildren();

	for (Section* resourceBuilding : building)
	{
		
	}
}

void City::collectTaxtes()
{
	//Loop over every citizen and Building
	//If Citizen, collect incomeTax and propretyTax
	//If building, collect businessTax and propretyTax (skip Service building)

	
}

void City::dealWithResources()
{

}

void City::dealWithPolicies()
{
	
}
