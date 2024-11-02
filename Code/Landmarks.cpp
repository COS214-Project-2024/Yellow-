#include "Landmarks.h"

Landmarks::Landmarks(string cellType) : Buildings(cellType) {}

void Landmarks::taxBuilding()
{
    float tax = buildingMoney * City::instanceCity().stuff.res->getPropertyTaxRate();
    buildingMoney -= tax;
    float cityMoney = City::instanceCity().stuff.res->getBudget();
    City::instanceCity().stuff.res->setBudget(cityMoney + tax);
}

void Landmarks::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}

void Landmarks::setIcon()
{
}

void Landmarks::payEmployees()
{
}