/**
 * @file Museum.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MUSEUM_H
#define MUSEUM_H

#include "Landmarks.h"
#include "City.h"

class Museum : public Landmarks {


public:
	Museum();
	void createBuildingResource() override;
    Cell* clone() override;
};

#endif