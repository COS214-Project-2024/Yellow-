#ifndef MUSEUM_H
#define MUSEUM_H

#include "Landmarks.h"
#include "City.h"

class Museum : public Landmarks {


public:
	Museum();
	void createBuildingResource() override;
    Cell* clone() override;
};

#endif