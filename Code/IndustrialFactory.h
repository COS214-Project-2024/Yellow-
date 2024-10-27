#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H
#include "BuildingFactory.h"
class IndustrialFactory : public BuildingFactory {


public:
	Industrial* createForestry() override;

	Industrial* createSteelFactory() override;

	Industrial* createConcreteFactory() override;

	Residential* createHouse() override;

	Residential* createApartment() override;

	Residential* createComplex() override;
	Landmarks* createPark() override;

	Landmarks* createMuseum() override;

	Service* createHospital() override;

	Service* createTownHall() override;

	Utilities* createWaterPlant() override;

	Utilities* createPowerPlant() override;

	Utilities* createWastePlant() override;

	Service* createSchool() override;

	Service* createTrainStation() override;

	Service* createAirport() override;

	Service* createPoliceStation() override;

	Commercial* createShop() override;

	Commercial* createOffice() override;

	Commercial* createMall() override;
};

#endif