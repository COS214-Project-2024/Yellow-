#ifndef WATERPLANT_H
#define WATERPLANT_H
#include "Utilities.h"
class WaterPlant : public Utilities {
    public:
    WaterPlant();
    void createResource() override;
    void setIcon() override;
    void payEmployees() override;
    void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif
