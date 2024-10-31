#ifndef FORESTRY_H
#define FORESTRY_H
#include "Industrial.h"
class Forestry : public Industrial {


public:
	Forestry();
	void createBuildingResource() override;
	void setIcon() override;
};

#endif