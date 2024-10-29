#ifndef STEELFACTORY_H
#define STEELFACTORY_H
#include "Industrial.h"
class SteelFactory : public Industrial {


public:
	float taxBuilding();
	void createBuildingResource() override;
};

#endif