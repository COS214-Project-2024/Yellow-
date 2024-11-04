/**
 * @file City.h
 * @author Stefan Muller
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CITY_H
#define CITY_H

#include "Resources.h"
#include "Government.h"

struct Varibals
{
	Resources* res = new Resources();
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
