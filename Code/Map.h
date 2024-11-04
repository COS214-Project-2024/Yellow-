/**
 * @file Map.h
 * @author Stefan and Johan Jansen van Rensburg
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
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
