/**
 * @file CVisitor.h
 * @author Stefan Muller
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CVISITOR_H
#define CVISITOR_H

#include "Visitor.h"
#include <iostream>

using namespace std;

class CVisitor : public Visitor {

public:
	void visitCitizens(Citizen* ele);

	void visitBuilding(Section* ele);
};

#endif
