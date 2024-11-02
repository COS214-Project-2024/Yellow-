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
    void setIcon() override;
    void addBuilding(Cell* building);
    void removeBuilding(Cell* building);
    Cell * clone() override;
    bool contains(Cell* object);
};

#endif
