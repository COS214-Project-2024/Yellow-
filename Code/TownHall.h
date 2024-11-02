#ifndef TOWNHALL_H
#define TOWNHALL_H
#include "Service.h"
class TownHall : public Service {
public:
    TownHall();
    void payEmployees() override;
    void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif
