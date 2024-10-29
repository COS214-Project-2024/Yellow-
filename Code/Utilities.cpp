#include "Utilities.h"

Utilities::Utilities(string cellType) : Buildings(cellType) {}

void Utilities::acceptVisitor(Visitor *v)
{
    // TODO - implement Utilities::acceptVisitor
	throw "Not yet implemented";
}

float Utilities::taxBuilding()
{
    return 0.0f;
}