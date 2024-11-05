/**
* @class ConcreteFactory
* @brief A class that represents a concrete factory.
* @ingroup Factory
* @implements Industrial
*
* The ConcreteFactory class is a concrete factory participant of the Factory design pattern. It is used to create a concrete factory building.
*/
#include "ConcreteFactory.h"

ConcreteFactory::ConcreteFactory() : Industrial("ConcreteFactory")
{
}

void ConcreteFactory::createBuildingResource()
{
    City c = City::instanceCity();
    int oldAmount = c.stuff.res->getConcrete();
    c.stuff.res->setConcrete(oldAmount + productionPerCell*coordinates.size()); // + any number - 90 chosen at random
}

void ConcreteFactory::setIcon()
{
}

Cell *ConcreteFactory::clone()
{
    Cell* c = new ConcreteFactory();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    setBaseForClone(c);
    return c;
}
