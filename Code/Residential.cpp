#include "Residential.h"

Residential::Residential(string cellType) : Buildings(cellType) {}

void Residential::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}
