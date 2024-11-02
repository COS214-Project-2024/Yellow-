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
	int propertyTaxRate;
	int incomeTaxRate;
	int businessTaxRate;
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
};

#endif
