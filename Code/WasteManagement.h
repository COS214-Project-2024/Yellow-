/**
 * @file WasteManagement.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H
#include "Utilities.h"
#include "City.h"
class WasteManagement : public Utilities {
public:
    WasteManagement();
    void createBuildingResource();
    void setIcon();
    Cell* clone();
};

#endif