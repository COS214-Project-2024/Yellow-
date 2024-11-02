#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Service.h"
class Hospital : public Service {
    public:
    Hospital();
    void setIcon() override;
    void payEmployees() override;
    void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif