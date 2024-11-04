/**
* @class TarRoad
* @brief Concrete implementation of the Road factory
* @ingroup Factory
* @implements Road
*
* The TarRoad class is a concrete factory participant of the Factory design pattern. It is used to create a tar road.
*/
#include "TarRoad.h"
TarRoad::TarRoad(int cost) {
    this->cost = cost;
}
