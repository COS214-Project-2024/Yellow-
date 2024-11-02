#include "LandmarkFactory.h"

Landmarks* LandmarkFactory::createPark(vector<Coordinate> coordinates) {
    int cells = coordinates.size();
    if (useBuildingResources(150,150,150,650,cells))
	    return new Park();
    return nullptr;
}

Landmarks* LandmarkFactory::createMuseum(vector<Coordinate> coordinates) {
    int cells = coordinates.size();
    if (useBuildingResources(150,150,150,650,cells))
	    return new Museum();
    return nullptr;
}

Service *LandmarkFactory::createHospital(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *LandmarkFactory::createTownHall(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *LandmarkFactory::createWaterPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *LandmarkFactory::createPowerPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *LandmarkFactory::createWastePlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *LandmarkFactory::createSchool(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *LandmarkFactory::createTrainStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *LandmarkFactory::createAirport(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *LandmarkFactory::createPoliceStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *LandmarkFactory::createHouse(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *LandmarkFactory::createApartment(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *LandmarkFactory::createComplex(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *LandmarkFactory::createHouseHold(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *LandmarkFactory::createForestry(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *LandmarkFactory::createSteelFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *LandmarkFactory::createConcreteFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *LandmarkFactory::createShop(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *LandmarkFactory::createOffice(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *LandmarkFactory::createMall(vector<Coordinate> coordinates)
{
    return nullptr;
}