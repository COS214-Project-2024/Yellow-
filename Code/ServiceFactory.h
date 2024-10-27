#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H
#include "BuildingFactory.h"
class ServiceFactory : public BuildingFactory{


public:
	Residential* createHouse();

	Residential* createApartment();

	Residential* createComplex();
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

	Industrial* createForestry() override;

	Industrial* createSteelFactory() override;

	Industrial* createConcreteFactory() override;

	Commercial* createShop() override;

	Commercial* createOffice() override;

	Commercial* createMall() override;
};

#endif