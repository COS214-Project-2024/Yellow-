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

	virtual Service* createHospital(vector<Coordinate> coordinates) = 0;

	virtual Service* createTownHall(vector<Coordinate> coordinates) = 0;

	virtual Utilities* createWaterPlant(vector<Coordinate> coordinates) = 0;

	virtual Utilities* createPowerPlant(vector<Coordinate> coordinates) = 0;

	virtual Utilities* createWastePlant(vector<Coordinate> coordinates) = 0;

	virtual Service* createSchool(vector<Coordinate> coordinates) = 0;

	virtual Service* createTrainStation(vector<Coordinate> coordinates) = 0;

	virtual Service* createAirport(vector<Coordinate> coordinates) = 0;

	virtual Service* createPoliceStation(vector<Coordinate> coordinates) = 0;

	virtual Residential* createHouse(vector<Coordinate> coordinates) = 0;

	virtual Residential* createApartment(vector<Coordinate> coordinates) = 0;

	virtual Residential* createComplex(vector<Coordinate> coordinates) = 0;

	virtual Residential* createHouseHold(vector<Coordinate> coordinates) = 0;

	virtual Industrial* createForestry(vector<Coordinate> coordinates) = 0;

	virtual Industrial* createSteelFactory(vector<Coordinate> coordinates) = 0;

	virtual Industrial* createConcreteFactory(vector<Coordinate> coordinates) = 0;

	virtual Commercial* createShop(vector<Coordinate> coordinates) = 0;

	virtual Commercial* createOffice(vector<Coordinate> coordinates) = 0;

	virtual Commercial* createMall(vector<Coordinate> coordinates) = 0;

	virtual Landmarks* createPark(vector<Coordinate> coordinates) = 0;

	virtual Landmarks* createMuseum(vector<Coordinate> coordinates) = 0;
	
	virtual ~BuildingFactory();
};

#endif