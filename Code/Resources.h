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
	float propertyTaxRate;
	float incomeTaxRate;
	float businessTaxRate;
	float wage;
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
    void setBusinessTaxRate(float newRate);
    void setPropertyTaxRate(float newRate);
    void setIncomeTaxRate(float newRate);
	void setWage(float newWage);

    // Getters
    int getConcrete();
    int getSteel();
    int getWood();
    int getPowerGrid();
    int getPowerUsage();
    int getWaterGrid();
    int getWaterUsage();
    float getBudget();
    int getPopulation();
    int getMorale();
    int getBusinessTax();
    float getPropertyTaxRate();
    float getIncomeTaxRate();
	float getBusinessTaxRate();
	float getWage();
};

#endif
