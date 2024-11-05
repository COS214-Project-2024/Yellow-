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

Cell* Cell::getCell() {
    return this;
}

string Cell::getCellType() {
    return this->type;
}

vector<Coordinate> Cell::getCoordinates() {
    return this->coordinates;
}

void Cell::setCoordinates(vector<Coordinate> newCoordinates) {
    this->coordinates = std::move(newCoordinates);
}

void Cell::setCellType(string str) {
    this->type = str;
}

Cell::~Cell()
{
}



Cell * Cell::clone() {

}




