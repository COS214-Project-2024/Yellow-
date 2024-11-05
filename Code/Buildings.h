/**
 * @file Buildings.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <vector>
#include "Section.h"
class Citizen;

class Buildings : public Section {
protected:
    int maxCitizens;
    int currentNumberOfCitizens;
    float buildingMoney;
    std::vector<Citizen*> dependentCitizens;
    int productionPerCell;						
	void setBaseForClone(Cell* cell);

public:
    Buildings(std::string cellType);

	float getMoney();

	void setMoney(float newAmount);
	
	int getMaxCitizens();

	void addSection(Cell* section);

	void removeSection(int idx);

	Cell* getSection(int idx);

	void acceptVisitor(Visitor* v);

	virtual void taxBuilding() = 0;

	virtual void payEmployees() = 0;

	virtual void setIcon();

	virtual void addCitizenToBuilding(Citizen* newCitizen) = 0;
	virtual Cell* clone() = 0;
	virtual void setProductionRate(int newRate);
	virtual void createBuildingResource() = 0;
	virtual ~Buildings();
};

#endif // BUILDINGS_H
