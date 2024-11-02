#include "TrainStation.h"

TrainStation::TrainStation() : Service("TrainStation")
{
}

void TrainStation::payEmployees()
{
}

void TrainStation::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *TrainStation::clone()
{
    Cell* c = new TrainStation();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
