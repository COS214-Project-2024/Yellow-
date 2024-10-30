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
