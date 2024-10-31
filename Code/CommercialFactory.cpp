#include "CommercialFactory.h"

Commercial* CommercialFactory::createShop(vector<Coordinate> coordinates) {
    if (useBuildingResources(100,100,100,800) == false)
        return nullptr;
	return new Shop();
}

Commercial* CommercialFactory::createOffice(vector<Coordinate> coordinates) {
    if (useBuildingResources(100,100,100,800) == false)
        return nullptr;
	return new Office();
}

Commercial* CommercialFactory::createMall(vector<Coordinate> coordinates) {
    if (useBuildingResources(100,100,100,800) == false)
        return nullptr;
	return new Mall();
}

Residential *CommercialFactory::createHouse(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *CommercialFactory::createApartment(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *CommercialFactory::createComplex(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *CommercialFactory::createHouseHold(vector<Coordinate> coordinates)
{
    return nullptr;
}

Landmarks *CommercialFactory::createPark(vector<Coordinate> coordinates)
{
    return nullptr;
}

Landmarks *CommercialFactory::createMuseum(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *CommercialFactory::createHospital(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *CommercialFactory::createTownHall(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *CommercialFactory::createWaterPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *CommercialFactory::createPowerPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *CommercialFactory::createWastePlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *CommercialFactory::createSchool(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *CommercialFactory::createTrainStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *CommercialFactory::createAirport(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *CommercialFactory::createPoliceStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *CommercialFactory::createForestry(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *CommercialFactory::createSteelFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *CommercialFactory::createConcreteFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}