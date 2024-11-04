/**
 * @file ConcreteFactory.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CONCRETEFACTORY_H
#define CONCRETEFACTORY_H
#include "Industrial.h"
#include "City.h"
class ConcreteFactory : public Industrial {


public:
	ConcreteFactory();
	void createBuildingResource() override;
	void setIcon() override;
    Cell* clone() override;
};

#endif