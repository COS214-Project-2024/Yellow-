#ifndef POLICESTATION_H
#define POLICESTATION_H
#include "Service.h"
class PoliceStation : public Service {
    public:
    PoliceStation();
    void payEmployees() override;
    void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif
