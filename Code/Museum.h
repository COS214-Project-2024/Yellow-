#ifndef MUSEUM_H
#define MUSEUM_H

#include "Landmarks.h"
#include "City.h"

class Museum : public Landmarks {


public:
	float taxBuilding();
	Museum();
	void createBuildingResource() override;
};

#endif