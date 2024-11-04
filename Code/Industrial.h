#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Buildings.h"

class Visitor;

class Industrial : public Buildings {
public:
    void setProductionRate(int newRate);
    Industrial(std::string cellType);

    void taxBuilding();
    void acceptVisitor(Visitor* v);
    virtual void createBuildingResource() = 0;
    virtual void setIcon();
    virtual Cell* clone() = 0;
    void payEmployees();
    void addCitizenToBuilding(Citizen* newCitizen);
};

#endif // INDUSTRIAL_H
