/**
 * @file Complex.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef COMPLEX_H
#define COMPLEX_H
#include "Residential.h"
class Complex : public Residential {


public:
	Complex();
    Cell* clone() override;
};

#endif