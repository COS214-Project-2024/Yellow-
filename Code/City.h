#ifndef CITY_H
#define CITY_H

#include "Resources.h"
#include "Taxes.h"
#include "Government.h"

struct Varibals
{
	Resources* res = new Resources();
	Taxes* tax = new Taxes();
};

class City {
public:
	Varibals stuff;
	City();
	static City& instanceCity();
	void collectResources();
	void collectTaxes();
	void dealWithResources();
	void dealWithPolicies();
};

#endif
