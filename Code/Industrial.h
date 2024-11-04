/**
 * @file Industrial.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Buildings.h"
#include "Visitor.h"

class Industrial : public Buildings {


public:
	Industrial(string cellType);
	
	virtual float taxBuilding() = 0;

	void acceptVisitor(Visitor* v);

	virtual void createBuildingResource() = 0;
};

#endif
