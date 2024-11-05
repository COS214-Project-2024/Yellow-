/**
* @class TrainStation
* @brief Class for the TrainStation service
* @ingroup Factory
* @implements Service
*
* The TrainStation class is a concrete service participant of the Factory design pattern. It is used to create a train station service.
*/
#include "TrainStation.h"

TrainStation::TrainStation() : Service("TrainStation")
{
}

Cell *TrainStation::clone()
{
    Cell* c = new TrainStation();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    setBaseForClone(c);
    return c;
}
