/**
 * @file Apartment.h
 * @author Stefan Muller
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef APARTMENT_H
#define APARTMENT_H
#include "Residential.h"
class Apartment : public Residential{


public:
	Apartment();
	void setIcon() override;
    Cell* clone() override;
};

#endif