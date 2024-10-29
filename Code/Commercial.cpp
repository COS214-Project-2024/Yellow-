#include "Commercial.h"

Commercial::Commercial(string cellType) : Buildings(cellType) {}

void Commercial::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}
