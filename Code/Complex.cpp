#include "Complex.h"

Complex::Complex() : Residential("Complex")
{
}

Cell *Complex::clone()
{
    Cell* c = new Complex();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
