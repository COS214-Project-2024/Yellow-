
#include "Resources.h"

Resources::Resources()
{
    wood = 0;
    steel = 0;
    concrete = 0;
    morale = 0;
    budget = 0.0;
    population = 0;
    propertyTaxRate = 0;
    incomeTaxRate = 0.0;
    wage = 0.0;
    businessTaxRate = 0.0;
    water = 0;
    energy = 0;
}

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

void Resources::setPropertyTaxRate(float newRate)
{
    propertyTaxRate = newRate;
}

float Resources::getPropertyTaxRate()
{
    return propertyTaxRate;
}

void Resources::setIncomeTaxRate(float newRate)
{
    incomeTaxRate = newRate;
}

float Resources::getIncomeTaxRate()
{
    return incomeTaxRate;
}

void Resources::setBusinessTaxRate(float newRate)
{
    businessTaxRate = newRate;
}

float Resources::getBusinessTaxRate()
{
    return businessTaxRate;
}

void Resources::setWage(float newWage)
{
    wage = newWage;
}

float Resources::getWage()
{
    return wage;
}
