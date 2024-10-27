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

class BuildingFactory {


protected:
	virtual Service* createHospital() = 0;

	virtual Service* createTownHall() = 0;

	virtual Utilities* createWaterPlant() = 0;

	virtual Utilities* createPowerPlant() = 0;

	virtual Utilities* createWastePlant() = 0;

	virtual Service* createSchool() = 0;

	virtual Service* createTrainStation() = 0;

	virtual Service* createAirport() = 0;

	virtual Service* createPoliceStation() = 0;

	virtual Residential* createHouse() = 0;

	virtual Residential* createApartment() = 0;

	virtual Residential* createComplex() = 0;

	virtual Industrial* createForestry() = 0;

	virtual Industrial* createSteelFactory() = 0;

	virtual Industrial* createConcreteFactory() = 0;

	virtual Commercial* createShop() = 0;

	virtual Commercial* createOffice() = 0;

	virtual Commercial* createMall() = 0;

	virtual Landmarks* createPark() = 0;

	virtual Landmarks* createMuseum() = 0;
};

#endif