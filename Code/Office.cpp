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
