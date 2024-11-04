/**
 * @file Intersection.h
 * @author Johan and Stefan Jansen van Rensburg
 * @brief 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef CODE_INTERSECTION_H
#define CODE_INTERSECTION_H
#include "Cell.h"
#include "Road.h"
#include <vector>
#include <map>

class Intersection : public Cell{
protected:
    vector<Cell*> intersections;
};


#endif //CODE_INTERSECTION_H
