#ifndef UTILITIES_H
#define UTILITIES_H
#include "Buildings.h"
#include "Visitor.h"

class Utilities : public Buildings {


public:
	Utilities(string cellType);
	void acceptVisitor(Visitor* v);
	virtual void taxBuilding();
	virtual void createResource() = 0;
	virtual void setIcon();
};

#endif