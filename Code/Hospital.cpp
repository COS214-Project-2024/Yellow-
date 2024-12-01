/**
* @class Hospital
* @brief Class for the Hospital service
* @ingroup Factory
* @implements Service
*
* The Hospital class is a concrete service participant of the Factory design pattern. It is used to create a hospital service.
*/
#include "Hospital.h"

Hospital::Hospital() : Service("Hospital")
{
}

void Hospital::setIcon()
{
}

Cell *Hospital::clone()
{
    Cell* c = new Hospital();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    setBaseForClone(c);
    return c;
}
