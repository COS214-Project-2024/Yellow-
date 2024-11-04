/**
 * @file SteelFactory.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef STEELFACTORY_H
#define STEELFACTORY_H
#include "Industrial.h"
class SteelFactory : public Industrial {


public:
	SteelFactory();
	float taxBuilding();
	void createBuildingResource() override;
};

#endif