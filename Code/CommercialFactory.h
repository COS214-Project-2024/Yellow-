#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include "BuildingFactory.h"

class CommercialFactory : public BuildingFactory {


public:
	Commercial* createShop(vector<Coordinate> coordinates) override;

	Commercial* createOffice(vector<Coordinate> coordinates) override;

	Commercial* createMall(vector<Coordinate> coordinates) override;

	Residential* createHouse(vector<Coordinate> coordinates) override;

	Residential* createApartment(vector<Coordinate> coordinates) override;

	Residential* createComplex(vector<Coordinate> coordinates) override;
	
	Residential* createHouseHold(vector<Coordinate> coordinates) override;

	Landmarks* createPark(vector<Coordinate> coordinates) override;

	Landmarks* createMuseum(vector<Coordinate> coordinates) override;

	Service* createHospital(vector<Coordinate> coordinates) override;

	Service* createTownHall(vector<Coordinate> coordinates) override;

	Utilities* createWaterPlant(vector<Coordinate> coordinates) override;

	Utilities* createPowerPlant(vector<Coordinate> coordinates) override;

	Utilities* createWastePlant(vector<Coordinate> coordinates) override;

	Service* createSchool(vector<Coordinate> coordinates) override;

	Service* createTrainStation(vector<Coordinate> coordinates) override;

	Service* createAirport(vector<Coordinate> coordinates) override;

	Service* createPoliceStation(vector<Coordinate> coordinates) override;

	Industrial* createForestry(vector<Coordinate> coordinates) override;

	Industrial* createSteelFactory(vector<Coordinate> coordinates) override;

	Industrial* createConcreteFactory(vector<Coordinate> coordinates) override;
};

#endif