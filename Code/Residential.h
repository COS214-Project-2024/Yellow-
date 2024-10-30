#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H
class Visitor;
#include "Buildings.h"

class Residential : public Buildings {

protected:
	int numberOfHouseholds;

public:
	Residential(string cellType);
	virtual float taxBuilding() = 0;

	void acceptVisitor(Visitor* v);
};

#endif
