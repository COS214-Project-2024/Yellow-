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
   vector<vector<int>> distanceMatrix;
   vector<Cell*> pos;
   //TODO: find out how to set distances between buildings
   void addToMatrix(Cell* object);

public:
    Map(vector<vector<Cell*>> map, vector<vector<int>> distanceMatrix, vector<Cell*> pos);
    Map();
    void addNode(Cell* object, int x, int y, int height, int width);//coordinates for top left of object(x,y)
    //updates map and distance matrix
    void addNode(Cell* object);
    void addNode(Cell* object, vector<Coordinate> coordinates);
    void printMap();
    void removeNode(Cell* object);
    void removeNode(Coordinate* coordinate);
};
#endif //GROUPPROJECT_MAP_H
