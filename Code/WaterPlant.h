/**
 * @file WaterPlant.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef WATERPLANT_H
#define WATERPLANT_H
#include "Utilities.h"
#include "City.h"
class WaterPlant : public Utilities {
    public:
    WaterPlant();
    void createBuildingResource() override;
    void setIcon() override;
    Cell* clone() override;
};

#endif
