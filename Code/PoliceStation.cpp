/**
* @class PoliceStation
* @brief Class that represents a House building
* @ingroup Factory
* @implements Residential factory
*
* The PoliceStation class is a concrete factory participant of the Factory design pattern. It is used to create a police station building.
*/
#include "PoliceStation.h"

PoliceStation::PoliceStation() : Service("Police")
{
}