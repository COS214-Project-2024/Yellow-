/**
 * @file Shop.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SHOP_H
#define SHOP_H
#include "Commercial.h"
class Shop : public Commercial {


public:
	Shop();
    Cell* clone();
};

#endif