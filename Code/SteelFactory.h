#ifndef STEELFACTORY_H
#define STEELFACTORY_H
#include "Industrial.h"
class SteelFactory : public Industrial {


public:
	SteelFactory();
	void createBuildingResource() override;
	void payEmployees() override;
    void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif