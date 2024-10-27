#ifndef LANDMARKS_H
#define LANDMARKS_H

#include "Visitor.h"
#include "Buildings.h"
#include "Buildings.h"
class Landmarks : public Buildings {

public:
	virtual float taxBuilding() = 0;

	void acceptVisitor(Visitor* v);
};

#endif