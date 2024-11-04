/**
* @class Apartment
* @brief Class that represents an Apartment building
* @ingroup Factory
* @implements Residential factory
*
* The Apartment class is a concrete factory participant of the Factory design pattern. It is used to create an apartment building.
*/
#include "Apartment.h"
Apartment::Apartment() : Residential("Apartment")
{
    maxCitizens = 5;
}

void Apartment::setIcon()
{
}

Cell *Apartment::clone()
{
    Cell* c = new Apartment();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}