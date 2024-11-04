#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include "Residential.h"
class HouseHold : public Residential {
public:
	HouseHold();
    Cell* clone() override;
	void setIcon() override;
private:
	float houseIncome;
};

#endif
