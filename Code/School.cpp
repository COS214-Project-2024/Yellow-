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
