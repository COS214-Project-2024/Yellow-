#ifndef ROAD_H
#define ROAD_H
#include "Cell.h"
#include "Coordinate.h"
#include "Buildings.h"
#include <vector>
class Road : public Cell{
protected:
    int cost;

public:
    Road();
    vector<Cell*> buildings;
    void setIcon();
    void addBuilding(Cell* building);
    void removeBuilding(Cell* building);
    Cell * clone();
    bool contains(Cell* object);
    void addCitizenToBuilding(Citizen* newCitizen);
    void setProductionRate(int newRate);
    void createBuildingResource();
    float getMoney();
    void setMoney(float newAmount);
};

#endif
