#ifndef CITY_H
#define CITY_H

#include "Resources.h"
#include "Government.h"
#include "Section.h"
#include "Population.h"
#include "Map.h"
#include "MaterialOrder.h"
#include <vector>
#include <cmath>

struct Varibals
{
	Population* population;
	Resources* res;
	Section* head;
	Map* map;
};

class City {

	private:
		int prevMoral;
		int prevPopulation;
		int prevBudget;
		Government gov;

	public:
		Varibals stuff;
		City();
		//City(Section* head);
		static City& instanceCity();
		void nextIteration();
		void collection();
		void dealWithPolicies();
};

#endif
