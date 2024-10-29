#include "Industrial.h"

Industrial::Industrial(string cellType) : Buildings(cellType) {}

void Industrial::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}
