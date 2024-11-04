#include "Complex.h"

Complex::Complex() : Residential("Complex")
{
    maxCitizens = 15;
}

Cell *Complex::clone()
{
    Cell* c = new Complex();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}

void Complex::setIcon()
{
}
