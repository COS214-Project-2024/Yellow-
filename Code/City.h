#ifndef CITY_H
#define CITY_H

#include "Resources.h"
#include "Taxes.h"
#include "Government.h"
#include "Section.h"
#include "Population.h"
#include <vector>

struct Varibals
{
	Population* population;
	Resources* res = new Resources();
	Taxes* tax = new Taxes();
	Section* head;
};

class City {
public:
	Varibals stuff;
	City(){}
	City(Section* head);
	static City& instanceCity();
	void collectResources();
	void collectTaxtes();
	void dealWithResources();
	void dealWithPolicies();
};

#endif
