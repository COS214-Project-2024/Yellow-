/**
 * @class AddPublicTransport
 * @brief  AddPublicTransport is a concrete strategy participant of the Strategy design pattern.
 * @ingroup Strategy
 * @implements Strategy
 * @see Strategy
 * 
 * AddPublicTransport is a concrete strategy participant of the Strategy design pattern. It is used to implement a policy that adds public transport to the city.
 * 
 */
#include "BuildingFactory.h"

bool BuildingFactory::useBuildingResources(int numSteel, int numConcrete, int numWood, float numBudget, int cellCount)
{
    City* city = &City::instanceCity();
    if (city != nullptr) {
        int s = city->stuff.res->getSteel();
        int c = city->stuff.res->getConcrete();
        int w = city->stuff.res->getWood();
        float b = city->stuff.res->getBudget();
        if (s < (numSteel * cellCount)  || c < (numConcrete * cellCount) || w < (numWood * cellCount)) 
            return false;
        else {
            city->stuff.res->setConcrete(c - (numConcrete * cellCount));
            city->stuff.res->setSteel(s - (numSteel * cellCount));
            city->stuff.res->setWood(w - (numWood * cellCount));
            city->stuff.res->setBudget(b - (numBudget * cellCount));
        }
    } else {
        return false;
    }
    return true;
}

BuildingFactory::~BuildingFactory()
{
}
