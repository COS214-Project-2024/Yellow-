/**
* @class School
* @brief  A concrete factory the participant of the Factory design pattern
* @ingroup Factory
* @implements Service
*
* The School class is a concrete service participant of the Factory design pattern. It is used to create a school service.
*/
#include "School.h"

School::School() : Service("School")
{
}

Cell *School::clone()
{
    Cell* c = new School();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
