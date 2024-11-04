/**
* @class Cell
* @brief Class that represents a cell in the city
* @ingroup Factory
* @implements Cell
*
* The Cell class is a concrete factory participant of the Factory design pattern. It is used to create a cell in the city.
*/
#include "Cell.h"

Cell::Cell(string cellType) {
    this->type = cellType;
}

string Cell::getCell() {
    return this->type;
}

Cell::~Cell()
{
}
