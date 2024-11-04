#ifndef SERVICE_H
#define SERVICE_H

#include "Visitor.h"
#include "Buildings.h"
#include "City.h"

class Service : public Buildings{


public:
	Service(string cellType);
	virtual void taxBuilding();
	void createBuildingResource();
	void acceptVisitor(Visitor* v);
	virtual void setIcon();
	virtual Cell* clone() = 0;
	void payEmployees();
	void addCitizenToBuilding(Citizen* newCitizen);
};

#endif
