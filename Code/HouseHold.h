#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include "Residential.h"
class HouseHold : public Residential {
public:
	HouseHold();
	void taxBuilding() override;
private:
	float houseIncome;
};

#endif
