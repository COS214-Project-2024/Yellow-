#include "Resources.h"

// Setter for materials
void Resources::setMaterials(int newAmount) {
    materials = newAmount;
}

// Getter for materials
int Resources::getMaterials() {
    return materials;
}

// Setter for energy
void Resources::setEnergy(int newAmount) {
    energy = newAmount;
}

// Getter for energy
int Resources::getEnergy() {
    return energy;
}

// Setter for water
void Resources::setWater(int newAmount) {
    water = newAmount;
}

// Getter for water
int Resources::getWater() {
    return water;
}

// Setter for budget
void Resources::setBudget(float newAmount) {
    budget = newAmount;
}

// Getter for budget
float Resources::getBudget() {
    return budget;
}

// Setter for population
void Resources::setPopulation(int newAmount) {
    population = newAmount;
}

// Getter for population
int Resources::getPopulation() {
    return population;
}

// Setter for morale
void Resources::setMorale(int newAmount) {
    morale = newAmount;
}

// Getter for morale
int Resources::getMorale() {
    return morale;
}
