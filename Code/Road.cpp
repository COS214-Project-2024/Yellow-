#include "Road.h"
Road::Road() : Cell("Road") {
    setCellType("Road");
    this->buildings = vector<Cell*>();
}

void Road::setIcon() {
    this->icon = 'R';
}

void Road::addBuilding(Cell *building) {
    if (building->getCellType() == "Road" || building->getCellType() == "Field")
        return;
    else{
        if (building->getCoordinates().size() == 0){
            return;
        }
        this->buildings.push_back(building);
    }
}

void Road::removeBuilding(Cell *building) {
    for (int K = 0; K < buildings.size(); ++K){
        if (buildings[K] == building){
            buildings.erase(buildings.begin() + K);
        }
    }
}

Cell *Road::clone() {
    //Cell* newRoad = new Road();
    //return newRoad;
}

bool Road::contains(Cell *object) {
    for (int K = 0; K < buildings.size(); ++K){
        if (buildings[K] == object){
            return true;
        }
    }
    return false;
}

void Road::addCitizenToBuilding(Citizen *newCitizen)
{
}

void Road::setProductionRate(int newRate)
{
}

void Road::createBuildingResource()
{
}

float Road::getMoney()
{
    return 0.0f;
}
