/**
* @class Complex
* @brief Class that represents a Complex building
* @ingroup Factory
* @implements Residential factory
*
* The Complex class is a concrete factory participant of the Factory design pattern. It is used to create a complex building.
*/
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
