#ifndef APARTMENT_H
#define APARTMENT_H
#include "Residential.h"
class Apartment : public Residential{


public:
	Apartment();
	void taxBuilding();
	void setIcon() override;
	void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif
