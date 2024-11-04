/**
 * @file Residential.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H
class Visitor;
#include "Buildings.h"
class Residential : public Buildings {

protected:
	int numberOfHouseholds;
public:
	Residential(string cellType);
	void taxBuilding();

	void acceptVisitor(Visitor* v);
	virtual void setIcon();

	void payEmployees() override;
	
	virtual Cell* clone() = 0;
	void addCitizenToBuilding(Citizen* newCitizen);
	void createBuildingResource() override;
};

#endif
