/**
 * @file Service.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SERVICE_H
#define SERVICE_H

#include "Visitor.h"
#include "Buildings.h"
#include "City.h"

class Service : public Buildings{


public:
	Service(string cellType);
	virtual void taxBuilding();
	void createBuildingResource() override;
	void acceptVisitor(Visitor* v);
	virtual void setIcon();
	virtual Cell* clone() = 0;
	void payEmployees() override;
	void addCitizenToBuilding(Citizen* newCitizen) override;
};

#endif
