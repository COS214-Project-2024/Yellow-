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
