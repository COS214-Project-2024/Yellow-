/**
 * @file ResidentialFactory.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H
#include "BuildingFactory.h"
class ResidentialFactory : public BuildingFactory {


public:
Cell* createHouse(vector<Coordinate> coordinates) override;

	Cell* createApartment(vector<Coordinate> coordinates) override;

	Cell* createComplex(vector<Coordinate> coordinates) override;

	Cell* createHouseHold(vector<Coordinate> coordinates) override;
	
	Cell* createPark(vector<Coordinate> coordinates) override;

	Cell* createMuseum(vector<Coordinate> coordinates) override;

	Cell* createHospital(vector<Coordinate> coordinates) override;

	Cell* createTownHall(vector<Coordinate> coordinates) override;

	Cell* createWaterPlant(vector<Coordinate> coordinates) override;

	Cell* createPowerPlant(vector<Coordinate> coordinates) override;

	Cell* createWastePlant(vector<Coordinate> coordinates) override;

	Cell* createSchool(vector<Coordinate> coordinates) override;

	Cell* createTrainStation(vector<Coordinate> coordinates) override;

	Cell* createAirport(vector<Coordinate> coordinates) override;

	Cell* createPoliceStation(vector<Coordinate> coordinates) override;

	Cell* createForestry(vector<Coordinate> coordinates) override;

	Cell* createSteelFactory(vector<Coordinate> coordinates) override;

	Cell* createConcreteFactory(vector<Coordinate> coordinates) override;

	Cell* createShop(vector<Coordinate> coordinates) override;

	Cell* createOffice(vector<Coordinate> coordinates) override;

	Cell* createMall(vector<Coordinate> coordinates) override;
};

#endif