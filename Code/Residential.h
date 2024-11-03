#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H
class Visitor;
#include "Buildings.h"
class Residential : public Buildings {

protected:
	int numberOfHouseholds;
public:
	Residential(string cellType);
	void taxBuilding() override;

	void acceptVisitor(Visitor* v);
	virtual void setIcon();

	void payEmployees() override;
	
	virtual Cell* clone() = 0;
	void addCitizenToBuilding(Citizen* newCitizen) override;
	void createBuildingResource() override;
};

#endif
