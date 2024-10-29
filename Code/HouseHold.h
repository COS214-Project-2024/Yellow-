#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include "Residential.h"
class HouseHold : public Residential {
public:
	HouseHold();
	float taxBuilding() override;
private:
	float houseIncome;
};

#endif
