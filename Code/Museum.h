#ifndef MUSEUM_H
#define MUSEUM_H

#include "Landmarks.h"

class Museum : public Landmarks {


public:
	void taxBuilding() override;
	Museum();
	void createBuildingResource() override;
};

#endif