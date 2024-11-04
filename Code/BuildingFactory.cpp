#include "BuildingFactory.h"

bool BuildingFactory::useBuildingResources(int numSteel, int numConcrete, int numWood, float numBudget, int cellCount)
{
    City* city = &City::instanceCity();
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
    return true;
}

BuildingFactory::~BuildingFactory()
{
}
