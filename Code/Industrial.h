#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Buildings.h"
#include "Visitor.h"

class Industrial : public Buildings {


public:
	Industrial(string cellType);
	
	virtual void taxBuilding();

	void acceptVisitor(Visitor* v);

	virtual void createBuildingResource() = 0;

	virtual void setIcon();
};

#endif
