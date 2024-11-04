#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Visitor.h"
#include "Buildings.h"
class Commercial : public Buildings {


public:
	Commercial(string cellType);
	
	void taxBuilding();

	void acceptVisitor(Visitor* v);
	
	virtual void setIcon();

	virtual Cell* clone() = 0;

	void payEmployees();
	
	void addCitizenToBuilding(Citizen* newCitizen);

	void createBuildingResource();
};

#endif