#ifndef COMPLEX_H
#define COMPLEX_H
#include "Residential.h"
class Complex : public Residential {


public:
	Complex();
	float taxBuilding();
	void setIcon() override;
};

#endif