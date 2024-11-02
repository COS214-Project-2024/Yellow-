//
// Created by sjvr0 on 2024/10/22.
//

#ifndef GROUPPROJECT_MAP_H
#define GROUPPROJECT_MAP_H

#include "Cell.h"
#include <iostream>
#include <vector>
#include "OpenField.h"
#include "Road.h"
using namespace std;
class Map {
private:
    //open spots on map: cellType = "Field"
   vector<vector<Cell*>> map;
   vector<vector<int>> distanceMatrix;
   vector<Cell*> pos;
   vector<Cell*> buildings;
   //TODO: deepCopy
   //TODO: aneurysm
   void addToMatrix(Cell* object);
   vector<Cell*> findBorderRoads(Cell* building);
   bool isInBounds(int r, int c);
   void removeFromMatrix(Cell* object);
   int findIndex(Cell* object);
   Cell* findObject(Coordinate coord);
    void setRoadConnections();

public:
    Map(const Map& other);
    Map(vector<vector<Cell*>> map, vector<vector<int>> distanceMatrix, vector<Cell*> pos);
    vector<Coordinate> returnFreeCoords();
    Map();
    void addNode(Cell* object, int x, int y, int height, int width);
    void addNode(Cell* object);
    void addNode(Cell* object, vector<Coordinate> coordinates);
    void printMap();
    void removeNode(Cell* object);
    void removeNode(Coordinate* coordinate);
    void djikstrasAneurysm(Cell* object);//TODO
    int retrieveDistance(Cell* res, Cell* job);
    //TODO: blocks system
};
#endif //GROUPPROJECT_MAP_H
