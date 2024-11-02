#include "Utilities.h"

Utilities::Utilities(string cellType) : Buildings(cellType) {}

void Utilities::acceptVisitor(Visitor *v)
{
    // TODO - implement Utilities::acceptVisitor
	throw "Not yet implemented";
}

void Utilities::taxBuilding()
{
    // do nothing
}

void Utilities::setIcon()
{
}

void Utilities::setProductionRate(int newRate)
{
    productionPerCell = newRate;
}

void Utilities::payEmployees()
{
}
