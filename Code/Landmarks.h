/**
 * @file Landmarks.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef LANDMARKS_H
#define LANDMARKS_H

#include "Visitor.h"
#include "Buildings.h"
#include "Buildings.h"
class Landmarks : public Buildings {

public:
	Landmarks(string cellType);

	void taxBuilding();

	void acceptVisitor(Visitor* v);

	virtual void createBuildingResource();
	
	virtual void setIcon();
	
	void payEmployees();

	void addCitizenToBuilding(Citizen* newCitizen);
};

#endif