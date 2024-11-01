#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H
class Visitor;
#include "Buildings.h"
#include <vector>
class Citizen;
class Residential : public Buildings {

protected:
	int numberOfHouseholds;
	vector<Citizen*> residents;
public:
	Residential(string cellType);
	virtual void taxBuilding() = 0;

	void acceptVisitor(Visitor* v);
	virtual void setIcon();

	virtual void payEmployees();

	virtual void addCitizenToBuilding();
};

#endif
