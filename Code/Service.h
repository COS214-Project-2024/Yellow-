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

class Service : public Buildings{


public:
	Service(string cellType);
	float taxBuilding();
	void createBuildingResource();
	void acceptVisitor(Visitor* v);
};

#endif
