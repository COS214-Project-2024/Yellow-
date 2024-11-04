#ifndef STEELFACTORY_H
#define STEELFACTORY_H
#include "Industrial.h"
#include "City.h"
class SteelFactory : public Industrial {


public:
	SteelFactory();
	float taxBuilding();
	void createBuildingResource() override;
};

#endif