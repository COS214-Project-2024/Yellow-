#ifndef OFFICE_H
#define OFFICE_H
#include "Commercial.h"
class Office : public Commercial {


public:
	void taxBuilding();
	Office();
	void setIcon() override;
	void payEmployees() override;
    void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif