#include "ResidentialFactory.h"

Residential* ResidentialFactory::createHouse(vector<Coordinate> coordinates) {
    if (useBuildingResources(50,50,50,500))
	    return new House();
    else 
        return nullptr;
}

Residential* ResidentialFactory::createApartment(vector<Coordinate> coordinates) { 
    if (useBuildingResources(50,50,50,500) == false)
        return nullptr;
    else
	    return new Apartment();
}

Residential* ResidentialFactory::createComplex(vector<Coordinate> coordinates) {
    if (useBuildingResources(50,50,50,500) == false)
        return nullptr;
    else
	    return new Complex();
}

Residential *ResidentialFactory::createHouseHold(vector<Coordinate> coordinates)
{
    if (useBuildingResources(50,50,50,500) == false)
        return nullptr;
    else
	    return new HouseHold();
}

Landmarks *ResidentialFactory::createPark(vector<Coordinate> coordinates)
{
    return nullptr;
}

Landmarks *ResidentialFactory::createMuseum(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *ResidentialFactory::createHospital(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *ResidentialFactory::createTownHall(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *ResidentialFactory::createWaterPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *ResidentialFactory::createPowerPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *ResidentialFactory::createWastePlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *ResidentialFactory::createSchool(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *ResidentialFactory::createTrainStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *ResidentialFactory::createAirport(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *ResidentialFactory::createPoliceStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *ResidentialFactory::createForestry(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *ResidentialFactory::createSteelFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *ResidentialFactory::createConcreteFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *ResidentialFactory::createShop(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *ResidentialFactory::createOffice(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *ResidentialFactory::createMall(vector<Coordinate> coordinates)
{
    return nullptr;
}