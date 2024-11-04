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
#include "ServiceFactory.h";
#include "ResidentialFactory.h";
#include "IndustrialFactory.h";
#include "CommercialFactory.h";
#include "LandmarkFactory.h";
class Cell;
class Industrial;
#include <vector>
#include <cmath>

struct Varibals
{
	Population* population;
	Resources* res;
	Section* head;
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
