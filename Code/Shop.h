#ifndef SHOP_H
#define SHOP_H
#include "Commercial.h"
class Shop : public Commercial {


public:
	Shop();
    Cell* clone();
};

#endif