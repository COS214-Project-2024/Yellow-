#include "ConcreteFactory.h"

ConcreteFactory::ConcreteFactory() : Industrial("ConcreteFactory")
{
}

void ConcreteFactory::createBuildingResource()
{
    City c = City::instanceCity();
    c.stuff.res->setConcrete(c.stuff.res->getConcrete() + 90); // + any number - 90 chosen at random
}

void ConcreteFactory::setIcon()
{
}

void ConcreteFactory::payEmployees()
{
}

void ConcreteFactory::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *ConcreteFactory::clone()
{
    Cell* c = new ConcreteFactory();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
