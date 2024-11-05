//
// Created by sjvr0 on 2024/11/04.
//

#ifndef CODE_ROADFACTORY_H
#define CODE_ROADFACTORY_H
#include "CellFactory.h"
#include "Road.h"
#include "Coordinate.h"
#include "City.h"

class RoadFactory : CellFactory{
public:

    Cell* createRoad(vector<Coordinate> coordinates);
    bool useBuildingResources(int numSteel, int numConcrete, int numWood, float numBudget, int cellCount);

};


#endif //CODE_ROADFACTORY_H
