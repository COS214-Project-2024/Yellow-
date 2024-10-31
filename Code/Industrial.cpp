#include "Industrial.h"

Industrial::Industrial(string cellType) : Buildings(cellType) {}

void Industrial::taxBuilding()
{
}

void Industrial::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}

void Industrial::setIcon()
{
}
