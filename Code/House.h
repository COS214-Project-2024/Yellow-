#ifndef HOUSE_H
#define HOUSE_H

#include "Residential.h"

class House : public Residential {


public:
	House();
	float taxBuilding();
	void setIcon() override;
};

#endif
