/**
* @class Residential
* @brief Class that represents a Residential building
* @ingroup Factory
* @implements Residential factory
*
* The Residential class is a concrete factory participant of the Factory design pattern. It is used to create a residential building.
*/
#include "Residential.h"

Residential::Residential(string cellType) : Buildings(cellType) {}

void Residential::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}
