#ifndef LANDMARKS_H
#define LANDMARKS_H

#include "Visitor.h"
#include "Buildings.h"
#include "Buildings.h"
class Landmarks : public Buildings {

public:
	Landmarks(string cellType);

	virtual void taxBuilding() = 0;

	void acceptVisitor(Visitor* v);

	virtual void createBuildingResource() = 0;
	
	virtual void setIcon();

	virtual void payEmployees();
	
	virtual Cell* clone() = 0;
};

#endif