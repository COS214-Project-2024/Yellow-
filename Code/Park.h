#ifndef PARK_H
#define PARK_H
#include "Landmarks.h"
class Park : public Landmarks {


public:
	Park();
	void createBuildingResource() override;
    Cell* clone() override;
};

#endif