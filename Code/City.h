#ifndef CITY_H
#define CITY_H
#include <vector>
#include "Resources.h"
#include "Government.h"
class Buildings;
struct Varibals
{
	Resources* res = new Resources();
};

class City {
protected:
	vector<Buildings*> buildings;
public:
	Varibals stuff;
	City();
	static City& instanceCity();
	void collectResources();
	void collectTaxes();
	void dealWithResources();
	void dealWithPolicies();
	void addBuilding(Cell* newBuilding);
	vector<Buildings*> getBuildings();
};

#endif
