#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Visitor.h"
#include "Buildings.h"
class Commercial : public Buildings {


public:
	virtual float taxBuilding() = 0;

	void acceptVisitor(Visitor* v);
};

#endif