/**
 * @file ServiceFactory.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H
#include "BuildingFactory.h"
class ServiceFactory : public BuildingFactory{


public:

Cell* createHouse(vector<Coordinate> coordinates);

	Cell* createApartment(vector<Coordinate> coordinates);

	Cell* createComplex(vector<Coordinate> coordinates);

	Cell* createHouseHold(vector<Coordinate> coordinates);
	
	Cell* createPark(vector<Coordinate> coordinates);

	Cell* createMuseum(vector<Coordinate> coordinates);

	Cell* createHospital(vector<Coordinate> coordinates);

	Cell* createTownHall(vector<Coordinate> coordinates);

	Cell* createWaterPlant(vector<Coordinate> coordinates);

	Cell* createPowerPlant(vector<Coordinate> coordinates);

	Cell* createWastePlant(vector<Coordinate> coordinates);

	Cell* createSchool(vector<Coordinate> coordinates);

	Cell* createTrainStation(vector<Coordinate> coordinates);

	Cell* createAirport(vector<Coordinate> coordinates);

	Cell* createPoliceStation(vector<Coordinate> coordinates);

	Cell* createForestry(vector<Coordinate> coordinates);

	Cell* createSteelFactory(vector<Coordinate> coordinates);

	Cell* createConcreteFactory(vector<Coordinate> coordinates);

	Cell* createShop(vector<Coordinate> coordinates);

	Cell* createOffice(vector<Coordinate> coordinates);

	Cell* createMall(vector<Coordinate> coordinates);
};

#endif