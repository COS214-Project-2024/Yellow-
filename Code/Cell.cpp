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
