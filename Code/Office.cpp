/**
* @classs Office
* @brief Class that represents an Office building
* @ingroup Factory
* @implements Commercial factory
*
* The Office class is a concrete factory participant of the Factory design pattern. It is used to create an office building.
*/
#include "Office.h"

Office::Office() : Commercial("Office")
{
}

void Office::setIcon()
{
}

Cell *Office::clone()
{
    Cell* c = new Office();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
