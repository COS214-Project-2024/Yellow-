#ifndef LANDMARKS_H
#define LANDMARKS_H

#include "Visitor.h"
#include "Buildings.h"
#include "Buildings.h"
class Landmarks : public Buildings {

public:
	Landmarks(string cellType);

	void taxBuilding() override;

	void acceptVisitor(Visitor* v);

	virtual void createBuildingResource() = 0;
	
	virtual void setIcon();
	
	void payEmployees() override;

	virtual Cell* clone() = 0;
};

#endif