/**
 * @file Coordinate.h
 * @author Stefan and Johan Jansen van Rensburg
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef CODE_COORDINATE_H
#define CODE_COORDINATE_H


class Coordinate {
public:
    int x = 0;
    int y = 0;
    Coordinate();
    Coordinate(int x, int y);
    int getX();
    int getY();
};


#endif //CODE_COORDINATE_H
