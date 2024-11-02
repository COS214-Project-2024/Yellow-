#ifndef RESOURCES_H
#define RESOURCES_H

class Resources {

private:
	int concrete;
	int steel;
	int wood;
	int energy;
	int water;
	float budget;
    int population;
    int morale;
	float propertyTaxRate;
	float incomeTaxRate;
	float businessTaxRate;
public:
	Resources();
	void setConcrete(int newAmount);
	int getConcrete();
	void setSteel(int newAmount);
	int getSteel();
	void setEnergy(int newAmount);
	int getEnergy();
	void setWater(int newAmount);
	int getWater();
	void setBudget(float newAmount);
	float getBudget();
	void setPopulation(int newAmount);
	int getPopulation();
	void setMorale(int newAmount);
	int getMorale();
	void setWood(int newAmount);
	int getWood();
	void setPropertyTaxRate(float newRate);
	float getPropertyTaxRate();
	void setIncomeTaxRate(float newRate);
	float getIncomeTaxRate();
	void setBusinessTaxRate(float newRate);
	float getBusinessTaxRate();
};

#endif
