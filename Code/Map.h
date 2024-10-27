//
// Created by sjvr0 on 2024/10/22.
//

#ifndef GROUPPROJECT_MAP_H
#define GROUPPROJECT_MAP_H
#include "Cell.h"
#include <iostream>
#include <vector>
using namespace std;
class Map {
private:
   vector<vector<Cell*>> map;
   vector<vector<Cell*>> distanceMatrix;

public:
    Map(vector<vector<Cell*>> map, vector<vector<Cell*>> distanceMatrix);
    void addNode(Cell* object, int x, int y, int height, int width);//coordinates for top left of object(x,y)
    //updates map and distance matrix
    void printMap();
};
#endif //GROUPPROJECT_MAP_H
