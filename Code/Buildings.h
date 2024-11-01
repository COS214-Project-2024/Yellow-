#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <iostream>
#include "Section.h"
#include "City.h"
class Buildings : public Section {

protected:
	int maxCitizens;
	int currentNumberOfCitizens;
	float buildingMoney;
private:
	int* sectionCoordinate;
public:
	Buildings(string cellType);

	float getMoney();

	void setMoney(float newAmount);
	
	int getMaxCitizens();

	void addSection(Section* section);

	void removeSection(int idx);

	Section* getSection(int idx);

	void acceptVisitor(Visitor* v);

	virtual void taxBuilding() = 0;

	virtual void payEmployees() = 0;

	virtual void setIcon();
};

#endif