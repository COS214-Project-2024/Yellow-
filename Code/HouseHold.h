#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include "Residential.h"
class HouseHold : public Residential {
public:
	HouseHold();
	void taxBuilding() override;
	void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
private:
	float houseIncome;
};

#endif
