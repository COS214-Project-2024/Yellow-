/**
 * @file PowerPlant.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef POWERPLANT_H
#define POWERPLANT_H
#include "Utilities.h"
#include "City.h"
class PowerPlant : public Utilities {
    public: 
        PowerPlant();

        void createBuildingResource() override;
    
        void addCitizenToBuilding(Citizen* newCitizen);
        
        Cell* clone() override;
};

#endif