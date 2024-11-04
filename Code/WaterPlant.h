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
class WaterPlant : public Utilities {
    public:
    WaterPlant();
    void createResource() override;
};

#endif
