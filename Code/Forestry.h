#ifndef FORESTRY_H
#define FORESTRY_H
#include "Industrial.h"
#include "City.h"
class Forestry : public Industrial {


public:
	Forestry();
	void createBuildingResource();
	void setIcon() override;
    Cell* clone();
};

#endif