#ifndef FORESTRY_H
#define FORESTRY_H
#include "Industrial.h"
#include "City.h"
class Forestry : public Industrial {


public:
	Forestry();
	float taxBuilding();
	void createBuildingResource() override;
};

#endif