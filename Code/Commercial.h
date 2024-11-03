#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Visitor.h"
#include "Buildings.h"
class Commercial : public Buildings {


public:
	Commercial(string cellType);
	
	void taxBuilding() override;

	void acceptVisitor(Visitor* v);
	
	virtual void setIcon();

	virtual Cell* clone() = 0;

	void payEmployees() override;
	
	void addCitizenToBuilding(Citizen* newCitizen) override;

	void createBuildingResource() override;
};

#endif