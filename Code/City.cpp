#include "City.h"

City::City()
{
	stuff.res = new Resources();
	gov = Government::onlyInstance();
	prevMoral = 0;
	prevBudget = 0;
	prevPopulation = 0;
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
	
}

void City::dealWithPolicies()
{
	MaterialOrder* orderMoral = nullptr;
	MaterialOrder* orderBudget = nullptr;
	MaterialOrder* orderPopulation = nullptr;
    
    //Moral
    if (stuff.res->getMorale() - prevMoral <= 0) {
        orderMoral = gov.handleMorale(false);
    } else {
        orderMoral = gov.handleMorale(false);
    }

	// for (auto &material : orderMoral->materials)							
	// {
	// 	if (material.first == "Morale")
	// 	{
	// 		stuff.res->setMorale(stuff.res->getMorale() + material.second);
	// 	}
	// }
	
	// //Budget
	// if (stuff.res->getBudget() - prevBudget < 0)
	// {
	// 	orderBudget = gov.handleBudget(false);
	// }
	// else 
	// {
	// 	orderBudget = gov.handleBudget(true);
	// }

	// for (auto &material : orderBudget->materials)							
	// {
	// 	if (material.first == "PropertyTax")
	// 	{
	// 		stuff.res->setPropertyTax(stuff.res->getPropertyTax() + material.second);
	// 		stuff.res->setMorale(stuff.res->getMorale() - 1);
	// 	}

	// 	if (material.first == "IncomeTax")
	// 	{
	// 		stuff.res->setIncomeTax(stuff.res->getIncomeTax() + material.second);
	// 		stuff.res->setMorale(stuff.res->getMorale() - 1);
	// 	}

	// 	if (material.first == "BusinessTax")
	// 	{
	// 		stuff.res->setBusinessTax(stuff.res->getBusinessTax() + material.second);
	// 		stuff.res->setMorale(stuff.res->getMorale() - 1);
	// 	}
	// }

	// //Population
	// if (stuff.res->getPopulation() - prevPopulation < 0)
	// {
	// 	orderPopulation = gov.handlePeople(true);
	// }
	// else 
	// {
	// 	orderPopulation = gov.handlePeople(false);
	// }

	// for (auto &material : orderPopulation->materials)
	// {
	// 	//Transport
	// 	if (material.first == "BusStop")
	// 	{
	// 		//stuff.map-> addNode(static_cast<Cell*>(serviceFactory->createBus()),0,0,1,1)
	// 	}
		
	// 	if (material.first == "TrainStation")
	// 	{
	// 		//stuff.map-> addNode(static_cast<Cell*>(serviceFactory->createTrainStation()),0,0,1,1);
	// 	}
		
	// 	if (material.first == "Morale")
	// 	{
	// 		stuff.res->setMorale(stuff.res->getMorale() + material.second);
	// 	}
			
	// 	//Bulding
	// }

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

	prevMoral = stuff.res->getMorale();
    prevBudget = stuff.res->getBudget();
    prevPopulation = stuff.res->getPopulation();
}
