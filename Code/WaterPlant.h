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
