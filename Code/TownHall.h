/**
 * @file TownHall.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef TOWNHALL_H
#define TOWNHALL_H
#include "Service.h"
class TownHall : public Service {
public:
    TownHall();
    Cell* clone() override;
};

#endif
