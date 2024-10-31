#ifndef APARTMENT_H
#define APARTMENT_H
#include "Residential.h"
class Apartment : public Residential{


public:
	Apartment();
	float taxBuilding();
	void setIcon() override;
};

#endif
