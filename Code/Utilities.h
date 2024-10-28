#ifndef UTILITIES_H
#define UTILITIES_H
#include "Buildings.h"
#include "Visitor.h"

class Utilities : public Buildings {


public:
	void acceptVisitor(Visitor* v);
	virtual float taxBuilding();
};

#endif