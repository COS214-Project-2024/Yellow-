#include "Commercial.h"

Commercial::Commercial(string cellType) : Buildings(cellType) {}

void Commercial::taxBuilding()
{
}

void Commercial::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}

void Commercial::setIcon()
{
}

void Commercial::payEmployees()
{
}
