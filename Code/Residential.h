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
	virtual float taxBuilding() = 0;

	void acceptVisitor(Visitor* v);
};

#endif
