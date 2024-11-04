/**
 * @file Park.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef PARK_H
#define PARK_H
#include "Landmarks.h"
#include "City.h"
class Park : public Landmarks {


public:
	Park();
	void createBuildingResource() override;
    Cell* clone();
};

#endif