#include "City.h"

City::City()
{
	stuff.res = new Resources();
	gov = Government::onlyInstance();
	prevMoral = 0;
	prevBudget = 0;
	prevPopulation = 0;
	stuff.people = new People(new Green());
    stuff.budget = new Budget(new Green());
    stuff.dissatisfaction = new Disatisfaction(new Green());
}

City &City::instanceCity()
{
    static City onlyInstance;
 	return onlyInstance;
}

void City::nextIteration()
{
	if (stuff.res == nullptr) {
        std::cerr << "Resources not initialized!" << std::endl;
        return;
    }
	collection();
	dealWithPolicies();
    stuff.res->printResources();
}

void City::collection()
{
	//Collect Resources


	//Collect Taxes
	//stuff.res->setMorale(stuff.res->getMorale() +50);
	
	stuff.res->setBudget(stuff.res->getBudget() + stuff.res->getBudget() * (stuff.res->getBusinessTax() + stuff.res->getIncomeTax() + stuff.res->getPropertyTax())/100);
}

void City::dealWithPolicies()
{
	MaterialOrder* orderMoral = nullptr;
	MaterialOrder* orderBudget = nullptr;
	MaterialOrder* orderPopulation = nullptr;
    
    //Moral
    if (stuff.res->getMorale() - prevMoral < 0) {
        gov.setStrategy(new IncreaseWages());
        orderMoral = gov.handleMorale(false);
    } else if (stuff.res->getMorale() - prevMoral >= 0) {
        orderMoral = gov.handleMorale(true);
    }

	if(orderMoral == nullptr){
		cout << "No new material order" << endl;
	}

    //Budget
    if (stuff.res->getBudget() - prevBudget < 0) {
        gov.setStrategy(new IncreaseTaxes());
        orderBudget = gov.handleBudget(false);
    } else if (stuff.res->getBudget() - prevBudget >= 0){
        gov.setStrategy(new AddPublicTransport());
        orderBudget = gov.handleBudget(true);
    }

	if(orderBudget == nullptr){
		cout << "No new material order" << endl;
	}

    //People
    if (stuff.res->getPopulation() - prevPopulation < 0) {
        orderPopulation = gov.handlePeople(true);

    } else if (stuff.res->getPopulation() - prevPopulation >= 0){
        gov.setStrategy(new ExpandCity());
        orderPopulation = gov.handlePeople(false);
    }

	if(orderPopulation == nullptr){
		cout << "No new material order" << endl;
	}

	if (orderMoral) {
        for (const auto& material : orderMoral->materials) {
            if (material.first == "Morale") {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
        }
    }

	if (orderBudget) {
        for (const auto& material : orderBudget->materials) {
            if (material.first == "PropertyTax") {
                stuff.res->setPropertyTax(stuff.res->getPropertyTax() + material.second);
                stuff.res->setMorale(stuff.res->getMorale() - 1);
            } else if (material.first == "IncomeTax") {
                stuff.res->setIncomeTax(stuff.res->getIncomeTax() + material.second);
                stuff.res->setMorale(stuff.res->getMorale() - 1);
            } else if (material.first == "BusinessTax") {
                stuff.res->setBusinessTax(stuff.res->getBusinessTax() + material.second);
                stuff.res->setMorale(stuff.res->getMorale() - 1);
            }
        }
    }

	if (orderPopulation) {
        for (const auto& material : orderPopulation->materials) {
            if (material.first == "BusStop") {
                // Add bus stop logic here if needed
            } else if (material.first == "TrainStation") {
                // Add train station logic here if needed
            } else if (material.first == "Morale") {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
        }
    }

	prevMoral = stuff.res->getMorale();
    prevBudget = stuff.res->getBudget();
    prevPopulation = stuff.res->getPopulation();

	//Increase or Deacrease population
	int populationAddedOrRemoved = floor(stuff.res->getPopulation()*(stuff.res->getMorale()/100.0));

	if (stuff.res->getMorale() <= 50)
	{
		stuff.res->setPopulation(stuff.res->getPopulation() - populationAddedOrRemoved);
	}
	else
	{
		stuff.res->setPopulation(stuff.res->getPopulation() + populationAddedOrRemoved);
	}
}
