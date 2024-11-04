/**
* @class Landmarks
* @brief Class that represents a Landmark building
* @ingroup Factory
* @implements Residential factory
*
* The Landmarks class is a concrete factory participant of the Factory design pattern. It is used to create a landmark building.
*/
#include "Landmarks.h"

Landmarks::Landmarks(string cellType) : Buildings(cellType) {}

void Landmarks::acceptVisitor(Visitor *v)
{
    v->visitBuilding(this);
}
