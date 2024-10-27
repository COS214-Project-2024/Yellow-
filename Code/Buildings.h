#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <iostream>
#include "Section.h"
class Buildings : public Section {

protected:
	int maxCitizens;
	int currentNumberOfCitizens;
private:
	int* sectionCoordinate;

public:
	int getMaxCitizens();

	void addSection(Section* section);

	void removeSection(Section* section);

	Section* getSection(int idx);

	void acceptVisitor(Visitor* v);

	virtual float taxBuilding() = 0;
};

#endif