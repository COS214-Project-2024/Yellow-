#ifndef POWERPLANT_H
#define POWERPLANT_H
#include "Utilities.h"
#include "City.h"
class PowerPlant : public Utilities {
    public: 
        PowerPlant();

        void createBuildingResource();
    
        void addCitizenToBuilding(Citizen* newCitizen);
        
        Cell* clone();
};

#endif