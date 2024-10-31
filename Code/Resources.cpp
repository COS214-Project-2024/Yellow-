#include "City.h"
#include "Resources.h"

Resources::Resources()
{
    concrete = 0;
    steel = 0;
    wood = 0;
    powerGrid = 150;
    powerUsage = 150;
    waterGrid = 150;
    waterUsage = 150;
	budget = 10000;
    population = 10;
    morale = 60;
    businessTax = 5;
    propertyTax = 7;
    incomeTax = 10;
}

void Resources::printResources()
{
    cout << "Population: " << population << endl;
    cout << "Budget: " << budget << endl;
    cout << "Moral: " << morale << "/100" << endl;
    cout << "Concrete: " << concrete << endl;
    cout << "Steel: " << steel << endl;
    cout << "Wood: " << wood << endl;
    cout << "Power: " << powerUsage << "/" << powerGrid << endl;
    cout << "Water: " << waterUsage << "/" << waterGrid << endl;
    cout << "Business Tax: " << businessTax << "%" << endl;
    cout << "Property Tax: " << propertyTax << "%" << endl;
    cout << "Income Tax: " << incomeTax << "%" << endl;
}

// Setters
void Resources::setConcrete(int newValue)
{ 
    concrete = newValue; 
}

void Resources::setSteel(int newValue) 
{ 
    steel = newValue; 
}

void Resources::setWood(int newValue) 
{ 
    wood = newValue; 
}

void Resources::setPowerGrid(int newValue) 
{ 
    powerGrid = newValue; 
}

void Resources::setPowerUsage(int newValue) 
{ 
    powerUsage = newValue; 
}

void Resources::setWaterGrid(int newValue) 
{ 
    waterGrid = newValue; 
}

void Resources::setWaterUsage(int newValue) 
{ 
    waterUsage = newValue; 
}

void Resources::setBudget(float newValue) 
{ 
    budget = newValue; 
}

void Resources::setPopulation(int newValue) 
{ 
    population = newValue; 
}

void Resources::setMorale(int newValue) 
{ 
    morale = min(newValue, 100);
}

void Resources::setBusinessTax(int newValue) 
{ 
    businessTax = newValue; 
}

void Resources::setPropertyTax(int newValue) 
{ 
    propertyTax = newValue; 
}

void Resources::setIncomeTax(int newValue) 
{ 
    incomeTax = newValue; 
}


// Getters
int Resources::getConcrete() const 
{ 
    return concrete; 
}

int Resources::getSteel() const 
{ 
    return steel; 
}

int Resources::getWood() const 
{ 
    return wood; 
}

int Resources::getPowerGrid() const 
{ 
    return powerGrid; 
}

int Resources::getPowerUsage() const 
{ 
    return powerUsage; 
}

int Resources::getWaterGrid() const 
{ 
    return waterGrid; 
}

int Resources::getWaterUsage() const 
{ 
    return waterUsage; 
}

float Resources::getBudget() const 
{ 
    return budget; 
}

int Resources::getPopulation() const 
{ 
    return population; 
}

int Resources::getMorale() const 
{ 
    return morale; 
}

int Resources::getBusinessTax() const 
{ 
    return businessTax; 
}

int Resources::getPropertyTax() const 
{ 
    return propertyTax; 
}

int Resources::getIncomeTax() const 
{ 
    return incomeTax; 
}

