/**
 * @file Airport.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef AIRPORT_H
#define AIRPORT_H
#include <vector>
#include "Service.h"
using namespace std;
class Airport : public Service{
    public:
        Airport();
        void setIcon() override;
        Cell* clone();
private:
    /*
    string destinations1;
    string destinations2;
    int timeGone;
    */
    //    //not sure we need this

    vector<Airport*> availableStops;
    vector<int> flyTime;
    //each flyTime index corresponds with availableStops index to indicate
    //how much time it takes to fly to each airport from this one
};

#endif