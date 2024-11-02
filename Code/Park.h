#ifndef PARK_H
#define PARK_H
#include "Landmarks.h"
class Park : public Landmarks {


public:
	void taxBuilding() override;
	Park();
	void createBuildingResource() override;
	void payEmployees() override;
    void addCitizenToBuilding(Citizen* newCitizen);
    Cell* clone() override;
};

#endif