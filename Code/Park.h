#ifndef PARK_H
#define PARK_H
#include "Landmarks.h"
#include "City.h"
class Park : public Landmarks {


public:
	float taxBuilding();
	Park();
	void createBuildingResource() override;
};

#endif