#include "Residential.h"

Residential::Residential(string cellType) : Buildings(cellType) {}

void Residential::taxBuilding()
{
}

void Residential::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}

void Residential::setIcon()
{
}

void Residential::payEmployees()
{
    // do nothing
}