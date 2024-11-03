#ifndef CITY_H
#define CITY_H
#include <vector>
#include "Resources.h"
#include "Government.h"
class Section;
class Cell;
struct Varibals
{
	Resources* res = new Resources();
};

class City {
protected:
	vector<Section*> buildings;
public:
	Varibals stuff;
	City();
	static City& instanceCity();
	void collectResources();
	void collectTaxes();
	void dealWithResources();
	void dealWithPolicies();
	void addBuilding(Cell* newBuilding);
	vector<Section*> getBuildings();
};

#endif
