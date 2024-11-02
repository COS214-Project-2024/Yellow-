#include "IndustrialFactory.h"
Cell* IndustrialFactory::createForestry(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	Industrial* f = new Forestry();
    f->setCoordinates(coordinates);
    return f;
}

Cell* IndustrialFactory::createSteelFactory(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700, coordinates.size()) == false)
        return nullptr;
	Industrial* s = new SteelFactory();
    s->setCoordinates(coordinates);
    return s;
}

Cell* IndustrialFactory::createConcreteFactory(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	return new ConcreteFactory();
}

Cell *IndustrialFactory::createHouse(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createApartment(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createComplex(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createHouseHold(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createPark(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createMuseum(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createHospital(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createTownHall(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createWaterPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createPowerPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createWastePlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createSchool(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createTrainStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createAirport(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createPoliceStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createShop(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createOffice(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *IndustrialFactory::createMall(vector<Coordinate> coordinates)
{
    return nullptr;
}
