#include "Landmarks.h"

Landmarks::Landmarks(string cellType) : Buildings(cellType) {}

void Landmarks::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}
