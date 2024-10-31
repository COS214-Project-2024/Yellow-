#ifndef AIRPORT_H
#define AIRPORT_H
#include <vector>
#include "Plane.h"
#include "Service.h"
using namespace std;
class Airport : public Service{
    public:
        Airport();
        void setIcon() override;
private:
    /*
    string destinations1;
    string destinations2;
    int timeGone;
    */
    //    //not sure we need this

    vector<Plane*> planes;
    vector<Airport*> availableStops;
    vector<int> flyTime;
    //each flyTime index corresponds with availableStops index to indicate
    //how much time it takes to fly to each airport from this one
};

#endif