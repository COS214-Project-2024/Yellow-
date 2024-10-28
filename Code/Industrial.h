#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Buildings.h"
#include "Visitor.h"

class Industrial : public Buildings {


public:
	virtual float taxBuilding() = 0;

	void acceptVisitor(Visitor* v);

	virtual void createBuildingResource() = 0;
};

#endif
