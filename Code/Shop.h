#ifndef SHOP_H
#define SHOP_H
#include "Commercial.h"
class Shop : public Commercial {


public:
	Shop();
	void taxBuilding();
	void payEmployees() override;
    void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif