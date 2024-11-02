#ifndef COMPLEX_H
#define COMPLEX_H
#include "Residential.h"
class Complex : public Residential {


public:
	Complex();
	void taxBuilding();
	void setIcon() override;
    void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif