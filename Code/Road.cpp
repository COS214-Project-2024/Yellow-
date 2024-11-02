#include "Road.h"
Road::Road() {
    setCellType("Road");
    this->buildings = new vector<Cell*>();
}

void Road::setIcon() {
    this->iccon = "R";
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
            buildings.erase(K);
        }
    }
}

Cell *Road::clone() {
    Cell* newRoad = road();
    return newRoad;
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
