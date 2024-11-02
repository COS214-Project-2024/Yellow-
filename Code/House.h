#ifndef HOUSE_H
#define HOUSE_H

#include "Residential.h"

class House : public Residential {


public:
	House();
	void taxBuilding();
	void setIcon() override;
	void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif
