/**
 * @file Commercial.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Visitor.h"
#include "Buildings.h"
class Commercial : public Buildings {


public:
	Commercial(string cellType);
	
	virtual float taxBuilding() = 0;

	void acceptVisitor(Visitor* v);
};

#endif