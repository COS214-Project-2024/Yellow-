/**
 * @file RandomUtil.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
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

