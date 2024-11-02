#ifndef TRAINSTATION_H
#define TRAINSTATION_H
#include <vector>
#include "Service.h"
class TrainStation : public Service{
    public:
    TrainStation();
    Cell* clone() override;
private:
    vector<TrainStation*> availableStops;
    vector<int> rideTime;
    //each rideTime index corresponds with availableStops index to indicate
    //how much time it takes to ride to each TrainStation from this one
};

#endif


