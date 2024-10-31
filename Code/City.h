#ifndef CITY_H
#define CITY_H

#include "Resources.h"
#include "Government.h"
#include "Section.h"
#include "Population.h"
#include "Map.h"
#include "MaterialOrder.h"
#include "BuildingFactory.h"
#include "IndustrialFactory.h"
#include "LandmarkFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "ServiceFactory.h"
#include <vector>

struct Varibals
{
	Population* population;
	Resources* res = new Resources();
	Section* head;
	Map* map;
};

class City {

	private:
		int prevMoral;
		int prevPopulation;
		int prevBudget;

	public:
		Varibals stuff;
		City();
		City(Section* head);
		static City& instanceCity();
		void nextIteration();
		void collection();
		void dealWithPolicies();
};

#endif
