/**
 * @file Buildings.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <iostream>
#include "Section.h"
#include "City.h"
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
};

#endif