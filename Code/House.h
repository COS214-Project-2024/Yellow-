/**
 * @file House.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef HOUSE_H
#define HOUSE_H

#include "Residential.h"

class House : public Residential {


public:
	House();
	float taxBuilding();
};

#endif
