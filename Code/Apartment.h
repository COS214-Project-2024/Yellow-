#ifndef APARTMENT_H
#define APARTMENT_H
#include "Residential.h"
class Apartment : public Residential{


public:
	Apartment();
	void setIcon() override;
    Cell* clone() override;
};

#endif