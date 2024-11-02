//
// Created by sjvr0 on 2024/10/29.
//

#ifndef CODE_INTERSECTION_H
#define CODE_INTERSECTION_H
#include "Cell.h"
#include "Road.h"
#include <vector>
#include <map>

class Intersection : public Cell{
protected:
    Cell * clone() override;
};


#endif //CODE_INTERSECTION_H
