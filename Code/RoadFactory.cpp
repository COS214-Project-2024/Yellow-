//
// Created by sjvr0 on 2024/11/04.
//

#include "RoadFactory.h"
Cell* RoadFactory::createRoad(vector<Coordinate> coordinates){
    if (useBuildingResources(0,10,0,100,coordinates.size()) == false)
        return nullptr;
    Road* road = new Road();
    road->setCoordinates(coordinates);
    return road;
}