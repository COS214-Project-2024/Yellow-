#include "SteelFactory.h"

SteelFactory::SteelFactory() : Industrial("SteelFactory")
{
}

void SteelFactory::createBuildingResource()
{
	if (&City::instanceCity() == nullptr)
        return;
    
    City c = City::instanceCity();
    c.stuff.res->setSteel(c.stuff.res->getSteel() + 90); // + any number - 90 chosen at random
}

void SteelFactory::payEmployees()
{
}

void SteelFactory::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *SteelFactory::clone()
{
    Cell* c = new SteelFactory();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
