/**
* @class TownHall
* @brief A class that represents the TownHall service
* @ingroup Factory
* @implements Service
*
* The TownHall class is a concrete service participant of the Factory design pattern. It is used to create a townhall service.
*/
#include "TownHall.h"

TownHall::TownHall() : Service("Townhall")
{
}