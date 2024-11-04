/**
* @class Commercial
* @brief Class that represents a Commercial building
* @ingroup Factory
* @implements Buildings
*
* The Commercial class is a concrete factory participant of the Factory design pattern. It is used to create a commercial building.
*/
#include "Commercial.h"

Commercial::Commercial(string cellType) : Buildings(cellType) {}

void Commercial::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}
