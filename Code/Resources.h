#ifndef RESOURCES_H
#define RESOURCES_H

class Resources {

private:
	int materials;
	int energy;
	int water;
	float budget;
    int population;
    int morale;

public:
	void setMaterials(int newAmount);
	int getMaterials();
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
};

#endif
