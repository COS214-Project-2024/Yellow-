/**
* @class Industrial
* @brief Class that represents an Industrial building
* @ingroup Factory
* @implements Buildings factory
*
* The Industrial class is a concrete factory participant of the Factory design pattern. It is used to create an industrial building.
*/
#include "Industrial.h"

Industrial::Industrial(string cellType) : Buildings(cellType) {}

void Industrial::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}
