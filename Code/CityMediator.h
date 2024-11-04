/**
 * @file CityMediator.h
 * @author Stefan Muller
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CITYMEDIATOR_H
#define CITYMEDIATOR_H

#include "Mediator.h"
#include "City.h"

class CityMediator : public Mediator {

public:
	City* colleagueList;

	void notify();
};

#endif
