#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H
#include "Utilities.h"
#include "City.h"
class WasteManagement : public Utilities {
public:
    WasteManagement();
    void createBuildingResource() override;
    void setIcon() override;
    Cell* clone() override;
};

#endif