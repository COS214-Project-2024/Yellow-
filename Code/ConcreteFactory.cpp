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

float ConcreteFactory::taxBuilding()
{
    // TODO - implement ConcreteFactory::taxBuilding
	throw "Not yet implemented";
}

void ConcreteFactory::createBuildingResource()
{
    City c = City::instanceCity();
    c.stuff.res->setConcrete(c.stuff.res->getConcrete() + 90); // + any number - 90 chosen at random
}
