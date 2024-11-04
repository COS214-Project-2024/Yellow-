#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <vector>
#include "Section.h"
#include "City.h"
class Citizen;

class Buildings : public Section {
protected:
    int maxCitizens;
    int currentNumberOfCitizens;
    float buildingMoney;
    std::vector<Citizen*> dependentCitizens;
    int productionPerCell;

public:
    Buildings(std::string cellType);

    float getMoney() override;
    void setMoney(float newAmount) override;

    int getMaxCitizens();
    void addSection(Section* section);
    void removeSection(int idx);
    Section* getSection(int idx);
    void acceptVisitor(Visitor* v);

    virtual void taxBuilding() = 0;
    virtual void payEmployees() = 0;
    virtual void setIcon();
    virtual void addCitizenToBuilding(Citizen* newCitizen) = 0;
    virtual Cell* clone() = 0;
    virtual void setProductionRate(int newRate);
    virtual void createBuildingResource() = 0;
    virtual ~Buildings();
};

#endif // BUILDINGS_H
