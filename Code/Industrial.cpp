#include "Industrial.h"

void Industrial::setProductionRate(int newRate)
{
    productionPerCell = newRate;
}

Industrial::Industrial(string cellType) : Buildings(cellType)
{
    productionPerCell = 0;
}

void Industrial::taxBuilding()
{
}

void Industrial::payEmployees()
{
}

void Industrial::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}

void Industrial::setIcon()
{
}
