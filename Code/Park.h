#ifndef PARK_H
#define PARK_H
#include "Landmarks.h"
class Park : public Landmarks {


public:
	float taxBuilding();
	Park();
	void createBuildingResource() override;
};

#endif