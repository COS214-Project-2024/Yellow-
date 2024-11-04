/**
 * @file Utilities.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef UTILITIES_H
#define UTILITIES_H
#include "Buildings.h"
#include "Visitor.h"

class Utilities : public Buildings {

protected:
	int productionPerCell;
public:
	Utilities(string cellType);
	void acceptVisitor(Visitor* v);
	virtual void taxBuilding();
	virtual void createBuildingResource() = 0;
	virtual void setIcon();
	virtual Cell* clone() = 0;
	void setProductionRate(int newRate) override;
	void payEmployees() override;
	void addCitizenToBuilding(Citizen* newCitizen) override;
};

#endif