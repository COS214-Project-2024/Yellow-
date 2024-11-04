#ifndef CITY_H
#define CITY_H
#include <vector>
#include "Resources.h"
#include "Government.h"
#include "Section.h"
#include "Population.h"
#include "Map.h"
#include "MaterialOrder.h"
#include "Severity.h"
#include "Green.h"
#include "IncreaseWages.h"
#include "IncreaseTaxes.h"
#include "ExpandCity.h"
#include "AddPublicTransport.h"
#include "Industrial.h"
#include <vector>
#include <cmath>

struct Varibals
{
	Population* population;
	Resources* res;
	Section* head;
	People* people;
    Budget* budget;
    Disatisfaction* dissatisfaction;
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
		void setHead(Section* head);
		static City& instanceCity();
		void nextIteration();
		void collection();
		void dealWithPolicies();

		void addBuilding(Cell *newBuilding);
};

#endif
