/**
* @class Government
* @brief Class that represents the government of the city
* @ingroup State, Strategy, Command, Chain of Responsibility
* @implements Department
*
* The Government class is a concrete handler participant of the Chain of Responsibility design pattern. It is used to handle the policies of the city.
*/
#include "HouseHold.h"

HouseHold::HouseHold() : Residential("Household")
{
    maxCitizens = 10;
}

Cell *HouseHold::clone()
{
    Cell* c = new HouseHold();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
