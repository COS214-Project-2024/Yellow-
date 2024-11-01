#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <iostream>
#include "Section.h"
class City;
class Buildings : public Section {

protected:
	int maxCitizens;
	int currentNumberOfCitizens;
private:
	int* sectionCoordinate;

public:
	Buildings(string cellType);
	
	int getMaxCitizens();

	void addSection(Section* section);

	void removeSection(int idx);

	Section* getSection(int idx);

	void acceptVisitor(Visitor* v);

	virtual float taxBuilding() = 0;

	virtual ~Buildings();
};

#endif