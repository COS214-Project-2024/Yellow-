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

Buildings::~Buildings()
{
	
}