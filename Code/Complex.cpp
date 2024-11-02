#include "Complex.h"

Complex::Complex() : Residential("Complex")
{
}

void Complex::taxBuilding()
{
}

void Complex::setIcon()
{
}

void Complex::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *Complex::clone()
{
    Cell* c = new Complex();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
