/**
* @class BuildingFactory
* @brief Class that represents the factory for creating buildings
* @ingroup Factory
* @implements BuildingFactory
*
* The BuildingFactory class is a concrete factory participant of the Factory design pattern. It is used to create buildings.
*/
#include "BuildingFactory.h"

bool BuildingFactory::useBuildingResources(int numSteel, int numConcrete, int numWood, float numBudget)
{
    City* city = &City::instanceCity();
    if (city != nullptr) {
        int s = city->stuff.res->getSteel();
        int c = city->stuff.res->getConcrete();
        int w = city->stuff.res->getWood();
        float b = city->stuff.res->getBudget();
        if (s < numSteel || c < numConcrete || w < numWood) 
            return false;
        else {
            city->stuff.res->setConcrete(c - numConcrete);
            city->stuff.res->setSteel(s - numSteel);
            city->stuff.res->setWood(w - numWood);
            city->stuff.res->setBudget(b - numBudget);
        }
    } else {
        return false;
    }
    return true;
}

BuildingFactory::~BuildingFactory()
{
}
