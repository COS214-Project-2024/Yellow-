#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
#include <cmath>
class Resources {

private:
	int concrete;
	int steel;
	int wood;
	int powerGrid;
	int powerUsage;
	int waterGrid;
	int waterUsage;
	float budget;
    int population;
    int morale;
	int businessTax;
	int propertyTax;
	int incomeTax;

public:

    Resources();
    void printResources();

	// Setters
    void setConcrete(int newValue);
    void setSteel(int newValue);
    void setWood(int newValue);
    void setPowerGrid(int newValue);
    void setPowerUsage(int newValue);
    void setWaterGrid(int newValue);
    void setWaterUsage(int newValue);
    void setBudget(float newValue);
    void setPopulation(int newValue);
    void setMorale(int newValue);
    void setBusinessTax(int newValue);
    void setPropertyTax(int newValue);
    void setIncomeTax(int newValue);

    // Getters
    int getConcrete() const;
    int getSteel() const;
    int getWood() const;
    int getPowerGrid() const;
    int getPowerUsage() const;
    int getWaterGrid() const;
    int getWaterUsage() const;
    float getBudget() const;
    int getPopulation() const;
    int getMorale() const;
    int getBusinessTax() const;
    int getPropertyTax() const;
    int getIncomeTax() const;
};

#endif
