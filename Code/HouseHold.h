#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include "Residential.h"
class HouseHold : public Residential {
public:
	HouseHold();
    Cell* clone() override;
private:
	float houseIncome;
};

#endif
