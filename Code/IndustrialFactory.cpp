#include "IndustrialFactory.h"
Cell* IndustrialFactory::createForestry(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	Industrial* f = new Forestry();
    f->setCoordinates(coordinates);
    f->setProductionRate(40);
    return f;
}

Cell* IndustrialFactory::createSteelFactory(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700, coordinates.size()) == false)
        return nullptr;
	Industrial* s = new SteelFactory();
    s->setCoordinates(coordinates);
    s->setProductionRate(40);
    return s;
}

Cell* IndustrialFactory::createConcreteFactory(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
    ConcreteFactory* c = new ConcreteFactory();
    c->setCoordinates(coordinates);
    c->setProductionRate(40);
    return c;
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
