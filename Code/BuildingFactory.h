#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H
#include "WasteManagement.h"
#include "WaterPlant.h"
#include "House.h"
#include "Apartment.h"
#include "Complex.h"
#include "School.h"
#include "Airport.h"
#include "PoliceStation.h"
#include "TrainStation.h"
#include "Hospital.h"
#include "TownHall.h"
#include "PowerPlant.h"
#include "Park.h"
#include "Museum.h"
#include "Forestry.h"
#include "SteelFactory.h"
#include "ConcreteFactory.h"
#include "Mall.h"
#include "Office.h"
#include "Shop.h"
#include "HouseHold.h"
#include "City.h"
#include "Coordinate.h"

#include <vector>

class BuildingFactory {


protected:
	bool useBuildingResources(int numSteel, int numConcrete, int numWood, float numBudget, int cellCount); // add to factory functions

	virtual Cell* createHospital(vector<Coordinate> coordinates) = 0;

	virtual Cell* createTownHall(vector<Coordinate> coordinates) = 0;

	virtual Cell* createWaterPlant(vector<Coordinate> coordinates) = 0;

	virtual Cell* createPowerPlant(vector<Coordinate> coordinates) = 0;

	virtual Cell* createWastePlant(vector<Coordinate> coordinates) = 0;

	virtual Cell* createSchool(vector<Coordinate> coordinates) = 0;

	virtual Cell* createTrainStation(vector<Coordinate> coordinates) = 0;

	virtual Cell* createAirport(vector<Coordinate> coordinates) = 0;

	virtual Cell* createPoliceStation(vector<Coordinate> coordinates) = 0;

	virtual Cell* createHouse(vector<Coordinate> coordinates) = 0;

	virtual Cell* createApartment(vector<Coordinate> coordinates) = 0;

	virtual Cell* createComplex(vector<Coordinate> coordinates) = 0;

	virtual Cell* createHouseHold(vector<Coordinate> coordinates) = 0;

	virtual Cell* createForestry(vector<Coordinate> coordinates) = 0;

	virtual Cell* createSteelFactory(vector<Coordinate> coordinates) = 0;

	virtual Cell* createConcreteFactory(vector<Coordinate> coordinates) = 0;

	virtual Cell* createShop(vector<Coordinate> coordinates) = 0;

	virtual Cell* createOffice(vector<Coordinate> coordinates) = 0;

	virtual Cell* createMall(vector<Coordinate> coordinates) = 0;

	virtual Cell* createPark(vector<Coordinate> coordinates) = 0;

	virtual Cell* createMuseum(vector<Coordinate> coordinates) = 0;
	
	virtual ~BuildingFactory();
};

#endif