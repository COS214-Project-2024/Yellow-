#ifndef UTILITIES_H
#define UTILITIES_H
#include "Buildings.h"
#include "Visitor.h"

class Utilities : public Buildings {

protected:
	int productionPerCell;
public:
	Utilities(string cellType);
	void acceptVisitor(Visitor* v);
	virtual void taxBuilding();
	virtual void createBuildingResource() = 0;
	virtual void setIcon();
	virtual Cell* clone() = 0;
	void setProductionRate(int newRate);
	void payEmployees();
	void addCitizenToBuilding(Citizen* newCitizen);
};

#endif