/**
 *@class Airport
 *@brief Class for the Airport service
 *@ingroup Factory
 *@implements Service
 * 
 * The Airport class is a concrete service participant of the Factory design pattern. It is used to create an airport service.
 */
#include "Airport.h"

Airport::Airport() : Service("Airport")
{
}

void Airport::setIcon()
{
}

Cell *Airport::clone()
{
    Cell* c = new Airport();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    setBaseForClone(c);
    return c;
}
