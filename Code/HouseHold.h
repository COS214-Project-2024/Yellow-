/**
 * @file HouseHold.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include "Residential.h"
class HouseHold : public Residential {
public:
	HouseHold();
    Cell* clone() override;
	void setIcon();
private:
	float houseIncome;
};

#endif
