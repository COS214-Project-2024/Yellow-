/**
 * @file Mall.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MALL_H
#define MALL_H
#include "Commercial.h"
class Mall : public Commercial {


public:
	Mall();
	float taxBuilding();
};

#endif