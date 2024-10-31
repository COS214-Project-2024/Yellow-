#include "IndustrialFactory.h"
Industrial* IndustrialFactory::createForestry(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	Industrial* f = new Forestry();
    f->setCoordinates(coordinates);
    return f;
}

Industrial* IndustrialFactory::createSteelFactory(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700, coordinates.size()) == false)
        return nullptr;
	Industrial* s = new SteelFactory();
    s->setCoordinates(coordinates);
    return s;
}

Industrial* IndustrialFactory::createConcreteFactory(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	return new ConcreteFactory();
}

Residential *IndustrialFactory::createHouse(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *IndustrialFactory::createApartment(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *IndustrialFactory::createComplex(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *IndustrialFactory::createHouseHold(vector<Coordinate> coordinates)
{
    return nullptr;
}

Landmarks *IndustrialFactory::createPark(vector<Coordinate> coordinates)
{
    return nullptr;
}

Landmarks *IndustrialFactory::createMuseum(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *IndustrialFactory::createHospital(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *IndustrialFactory::createTownHall(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *IndustrialFactory::createWaterPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *IndustrialFactory::createPowerPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Utilities *IndustrialFactory::createWastePlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *IndustrialFactory::createSchool(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *IndustrialFactory::createTrainStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *IndustrialFactory::createAirport(vector<Coordinate> coordinates)
{
    return nullptr;
}

Service *IndustrialFactory::createPoliceStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *IndustrialFactory::createShop(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *IndustrialFactory::createOffice(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *IndustrialFactory::createMall(vector<Coordinate> coordinates)
{
    return nullptr;
}
