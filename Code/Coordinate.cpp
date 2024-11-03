//
// Created by sjvr0 on 2024/10/28.
//

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