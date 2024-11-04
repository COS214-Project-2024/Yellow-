/**
* @class Save
* @brief A class used to save the current state of a city
* @ingroup Momento
* @implements SystemState
*
* The Save class is a concrete participant of the Momento design pattern. It is used to save the current state of a city.
*/
#include "Save.h"

Save::Save(Map* map, Varibals* systemState)
{
    this->map = map;
    this->systemState = systemState;
}

Save::~Save()
{
    delete this->map;
    delete this->systemState;
}

Varibals* Save::getSystemState()
{
    return this->systemState;
}

void Save::setSystemState(Varibals *sState)
{
    this->systemState = sState;
}

Map* Save::getMap()
{
    return this->map;
}

void Save::setMap(Map *map)
{
    this->map = map;
}

