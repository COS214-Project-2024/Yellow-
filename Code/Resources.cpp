/**
* @class Resources
* @brief A class that stores the resources of the city
* @ingroup Resources
* @implements Resources
*
* The Resources class is a concrete participant of the Resources design pattern. It is used to store the resources of the city.
*/

#include "Resources.h"

void Resources::setConcrete(int newAmount)
{
    concrete = newAmount;
}

int Resources::getConcrete()
{
    return concrete;
}

void Resources::setSteel(int newAmount)
{
    steel = newAmount;
}

int Resources::getSteel()
{
    return steel;
}

void Resources::setEnergy(int newAmount)
{
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

void Resources::setWood(int newAmount)
{
    wood = newAmount;
}

int Resources::getWood()
{
    return this->wood;
}
