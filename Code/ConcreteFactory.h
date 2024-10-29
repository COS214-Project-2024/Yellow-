#ifndef CONCRETEFACTORY_H
#define CONCRETEFACTORY_H
#include "Industrial.h"
class ConcreteFactory : public Industrial {


public:
	ConcreteFactory();
	float taxBuilding();
	void createBuildingResource() override;
};

#endif