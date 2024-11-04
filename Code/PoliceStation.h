/**
 * @file PoliceStation.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef POLICESTATION_H
#define POLICESTATION_H
#include "Service.h"
class PoliceStation : public Service {
    public:
    PoliceStation();
    Cell* clone() override;
};

#endif
