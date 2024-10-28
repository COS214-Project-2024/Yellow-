
#include "Resources.h"

void Resources::setMaterials(int newAmount) {
    this->materials = newAmount;
}

int Resources::getMaterials() {
    return this->materials;
}

void Resources::setEnergy(int newAmount) {
    this->energy = newAmount;
}

int Resources::getEnergy() {
    return this->energy;
}

void Resources::setWater(int newAmount) {
    this->water = newAmount;
}

int Resources::getWater() {
    return this->water;
}

void Resources::setBudget(float newAmount) {
    this->budget = newAmount;
}

float Resources::getBudget() {
    return this->budget;
}

void Resources::setPopulation(int newAmount) {
    this->population = newAmount;
}

int Resources::getPopulation() {
    return this->population;
}

void Resources::setMorale(int newAmount) {
    this->morale = newAmount;
}

int Resources::getMorale() {
    return this->morale;
}

