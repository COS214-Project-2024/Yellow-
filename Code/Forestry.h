/**
 * @file Forestry.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef FORESTRY_H
#define FORESTRY_H
#include "Industrial.h"
#include "City.h"
class Forestry : public Industrial {


public:
	Forestry();
	void createBuildingResource() override;
	void setIcon() override;
    Cell* clone();
};

#endif