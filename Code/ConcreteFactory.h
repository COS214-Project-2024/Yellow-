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