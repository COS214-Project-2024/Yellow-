/**
* @class Utilities
* @brief A class used to represent a utility building
* @ingroup Factory
* @implements Utilities factory
*
* The Utilities class is a concrete factory participant of the Factory design pattern. It is used to create a utility building.
*/
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