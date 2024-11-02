#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H
#include "Utilities.h"
class WasteManagement : public Utilities {
public:
    WasteManagement();
    void createResource() override;
    void setIcon() override;
    void payEmployees() override;
    void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif