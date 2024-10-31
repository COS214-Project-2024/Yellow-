#include "City.h"

City::City()
{
	prevMoral = 0;
	prevBudget = 0;
	prevPopulation = 0;
}

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

void City::nextIteration()
{
	collection();
	dealWithPolicies();
	stuff.res->printResources();
}

void City::collection()
{
	
}

void City::dealWithPolicies()
{
	Government &gov = Government::onlyInstance();

	MaterialOrder* orderMoral;
	MaterialOrder* orderBudget;
	MaterialOrder* orderPopulation;

	//Moral
	if (stuff.res->getMorale() - prevMoral < 0)
	{
		orderMoral = gov.handleMorale(true);
	}
	else 
	{
		orderMoral = gov.handleMorale(false);
	}

	vector<string, float>::iterator itr;

	for (itr = orderMoral->materials.begin(); itr != orderMoral->materials.end(); itr++)							
	{
		if (*itr->first == "Morale")
		{
			stuff.res->setMorale(stuff.res->getMorale() + *itr->second);
		}
	}
	
	//Budget
	if (stuff.res->getBudget() - prevBudget < 0)
	{
		orderBudget = gov.handleBudget(false);
	}
	else 
	{
		orderBudget = gov.handleBudget(true);
	}

	for (itr = orderBudget->materials.begin(); itr != orderBudget->materials.end(); itr++)							
	{
		if (*itr->first == "PropertyTax")
		{
			stuff.res->setPropertyTax(stuff.res->getPropertyTax() + *itr->second);
			stuff.res->setMorale(stuff.res->getMorale() - 1);
		}

		if (*itr->first == "IncomeTax")
		{
			stuff.res->setIncomeTax(stuff.res->getIncomeTax() + *itr->second);
			stuff.res->setMorale(stuff.res->getMorale() - 1);
		}

		if (*itr->first == "BusinessTax")
		{
			stuff.res->setBusinessTax(stuff.res->getBusinessTax() + *itr->second);
			stuff.res->setMorale(stuff.res->getMorale() - 1);
		}
	}

	//Population
	if (stuff.res->getPopulation() - prevPopulation < 0)
	{
		orderPopulation = gov.handlePeople(true);
	}
	else 
	{
		orderPopulation = gov.handlePeople(false);
	}

	for (itr = orderPopulation->materials.begin(); itr != orderPopulation->materials.end(); itr++)
	{
		BuildingFactory* serviceFactory = new ServiceFactory();
		BuildingFactory* residentialFactory = new ResidentialFactory();
		BuildingFactory* industrialFactory = new IndustrialFactory();
		BuildingFactory* commercialFactory = new CommercialFactory();
		BuildingFactory* landmarkFactory = new LandmarkFactory();
		//Transport
		if (*itr->first == "BusStop")
		{
			//stuff.map-> addNode(static_cast<Cell*>(serviceFactory->createBus()),0,0,1,1)
		}
		
		if (*itr->first == "TrainStation")
		{
			//stuff.map-> addNode(static_cast<Cell*>(serviceFactory->createTrainStation()),0,0,1,1);
		}
		
		if (*itr->first == "Morale")
		{
			stuff.res->setMorale(stuff.res->getMorale() + *itr->second);
		}
			
		//Bulding
	}

	//Increase or Deacrease population
	int populationAddedOrRemoved = stuff.res->getPopulation()*(stuff.res->getMorale()/100);

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
