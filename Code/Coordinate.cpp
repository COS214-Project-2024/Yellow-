/**
* @class Coordinate
* @brief 
* @ingroup 
* @implements 
*
* Creates coordinates to use in the map class
*/

#include "Coordinate.h"
Coordinate::Coordinate() {
    this->x = 0;
    this->y = 0;
}

Coordinate::Coordinate(int x, int y) {
    this->x = x;
    this-> y = y;
}

int Coordinate::getX() {
    return x;
}

int Coordinate::getY() {
    return y;
}