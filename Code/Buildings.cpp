/**
* @class Buildings
* @brief Buildings class
* @ingroup Composite
* @implements Section
*
* The Buildings class is a composite participant of the Composite design pattern. It is used to represent a building.
*/

#include "Buildings.h"

void Buildings::addSection(Section* section){}

void Buildings::removeSection(int idx){}

Section* Buildings::getSection(int idx)
{
	return nullptr;
}

void Buildings::acceptVisitor(Visitor* v){}

Buildings::Buildings(string cellType) : Section(cellType) {}

int Buildings::getMaxCitizens()
{
    return this->maxCitizens;
}
