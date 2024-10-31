#include "Utilities.h"

Utilities::Utilities(string cellType) : Buildings(cellType) {}

void Utilities::acceptVisitor(Visitor *v)
{
    // TODO - implement Utilities::acceptVisitor
	throw "Not yet implemented";
}

void Utilities::taxBuilding()
{
    return 0.0f;
}

void Utilities::setIcon()
{
}
