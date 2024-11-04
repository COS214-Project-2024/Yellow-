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


public:
	Utilities(string cellType);
	void acceptVisitor(Visitor* v);
	virtual float taxBuilding();
	virtual void createResource() = 0;
};

#endif