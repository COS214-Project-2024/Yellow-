/**
* @classs Office
* @brief Class that represents an Office building
* @ingroup Factory
* @implements Commercial factory
*
* The Office class is a concrete factory participant of the Factory design pattern. It is used to create an office building.
*/
#include "Office.h"

float Office::taxBuilding() {
	// TODO - implement Office::taxBuilding
	throw "Not yet implemented";
}

Office::Office() : Commercial("Office")
{
}