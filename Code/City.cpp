/**
* @class City
* @brief Class that represents a city
* @ingroup Factory
* @implements City
*
* The City class is a concrete factory participant of the Factory design pattern. It is used to create a city.
*/
#include "City.h"
#include <typeinfo>
#include "Buildings.h"
City::City()
{
	stuff.res = new Resources();
	gov = Government::onlyInstance();
	prevMoral = 0;
	prevBudget = 0;
	prevPopulation = 0;
}

void City::setHead(Section* head)
{
    this->stuff.head = head;
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
    vector<Cell*> building = stuff.head->getChildren();
    for(Cell* build : building)
    {
        if (build)
        {
            build->createBuildingResource();
            build->taxBuilding();
        }
    }
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

	if (orderMoral) 
    {
        for (const auto& material : orderMoral->materials) 
        {
            if (material.first == "Morale") 
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "Budget")
            {
                stuff.res->setBudget(stuff.res->getBudget() + material.second);
            }
        }
    }

	if (orderBudget) {
        for (const auto& material : orderBudget->materials) {
            if (material.first == "PropertyTax") 
            {
                stuff.res->setPropertyTaxRate(stuff.res->getPropertyTaxRate() + material.second);
                stuff.res->setMorale(stuff.res->getMorale() - 1);
            } 
            else if (material.first == "IncomeTax") {
                stuff.res->setIncomeTaxRate(stuff.res->getIncomeTaxRate() + material.second);
                stuff.res->setMorale(stuff.res->getMorale() - 1);
            } 
            else if (material.first == "BusinessTax") {
                stuff.res->setBusinessTaxRate(stuff.res->getBusinessTaxRate() + material.second);
                stuff.res->setMorale(stuff.res->getMorale() - 1);
            }
        }
    }

    ServiceFactory* serviceFactory = new ServiceFactory();
    ResidentialFactory* residentialFactory = new ResidentialFactory();
    IndustrialFactory* industrialFactory = new IndustrialFactory();
    CommercialFactory* commercialFactory = new CommercialFactory();
    LandmarkFactory* landmarkFactory = new LandmarkFactory();

    Coordinate c1 = Coordinate();
    vector<Coordinate> v1 = vector<Coordinate>();
    v1.push_back(c1);

	if (orderPopulation) {
        for (const auto& material : orderPopulation->materials) {
            if (material.first == "Morale") 
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "BusStop") 
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "TrainStation") 
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            } 
            else if (material.first == "MoraleIncrease")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "House")
            {
                stuff.head->addSection(residentialFactory->createHouse(v1));
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "Apartment")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "Complex")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "PowerPlant")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
                stuff.res->setPowerGrid(stuff.res->getPowerGrid() + 150);
            }
            else if (material.first == "WaterPlant")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
                stuff.res->setWaterGrid(stuff.res->getWaterGrid() + 150);
            }
            else if (material.first == "WasteManagement")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "ConcreteFactory")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "SteelFactory")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "Forestry")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "School")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "Hospital")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "PoliceStation")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "Mall")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "Office")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "Shop")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "Museum")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
            else if (material.first == "Park")
            {
                stuff.res->setMorale(stuff.res->getMorale() + material.second);
            }
        }
    }

	prevMoral = stuff.res->getMorale();
    prevBudget = stuff.res->getBudget();
    prevPopulation = stuff.res->getPopulation();

	//Increase or Deacrease population
	int populationAddedOrRemoved = floor(stuff.res->getPopulation()*(stuff.res->getMorale()/100.0));

	if (stuff.res->getMorale() <= 80)
	{
		stuff.res->setPopulation(stuff.res->getPopulation() - populationAddedOrRemoved);
	}
	else
	{
		stuff.res->setPopulation(stuff.res->getPopulation() + populationAddedOrRemoved);
	}

    stuff.res->setPowerUsage(stuff.res->getPopulation() * 4);
    stuff.res->setWaterUsage(stuff.res->getPopulation() * 4);
}