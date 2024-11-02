#ifndef POWERPLANT_H
#define POWERPLANT_H
#include "Utilities.h"
class PowerPlant : public Utilities {
    public: 
        PowerPlant();

        void createResource() override;

        void payEmployees() override;
    
        void addCitizenToBuilding(Citizen* newCitizen);
        
        Cell* clone() override;
};

#endif