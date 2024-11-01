#ifndef SERVICE_H
#define SERVICE_H

#include "Visitor.h"
#include "Buildings.h"
#include "City.h"

class Service : public Buildings{


public:
	Service(string cellType);
	float taxBuilding();
	void createBuildingResource();
	void acceptVisitor(Visitor* v);
};

#endif
