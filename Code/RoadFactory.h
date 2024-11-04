//
// Created by sjvr0 on 2024/11/04.
//

#ifndef CODE_ROADFACTORY_H
#define CODE_ROADFACTORY_H
#include "CellFactory.h"
#include "Road.h"
#include "Coordinate.h"
class RoadFactory : CellFactory{
public:
    Cell* createRoad(vector<Coordinate> coordinates);


};


#endif //CODE_ROADFACTORY_H
