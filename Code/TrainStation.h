/**
 * @file TrainStation.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef TRAINSTATION_H
#define TRAINSTATION_H
#include <vector>
#include "Service.h"
class TrainStation : public Service{
    public:
    TrainStation();
private:
    vector<TrainStation*> availableStops;
    vector<int> rideTime;
    //each rideTime index corresponds with availableStops index to indicate
    //how much time it takes to ride to each TrainStation from this one
};

#endif


