#ifndef CONCRETEFACTORY_H
#define CONCRETEFACTORY_H
#include "Industrial.h"
class ConcreteFactory : public Industrial {


public:
	ConcreteFactory();
	void createBuildingResource() override;
	void setIcon() override;
	void payEmployees() override;
    void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif