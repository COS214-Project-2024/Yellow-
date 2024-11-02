#include "TrainStation.h"

TrainStation::TrainStation() : Service("TrainStation")
{
}

Cell *TrainStation::clone()
{
    Cell* c = new TrainStation();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
