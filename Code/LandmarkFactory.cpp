/**
* @class LandmarkFactory
* @brief Class that represents a Landmark Factory
* @ingroup Factory
* @implements BuildingFactory
*
* The LandmarkFactory class is a concrete factory participant of the Factory design pattern. It is used to create landmark buildings.
*/
#include "LandmarkFactory.h"

Cell* LandmarkFactory::createPark(vector<Coordinate> coordinates) {
    int cells = coordinates.size();
    if (useBuildingResources(150,150,150,650,cells) == false)
        return nullptr;
    Park* p = new Park();
    p->setCoordinates(coordinates);
    p->setProductionRate(1);
    return p;
}

Cell* LandmarkFactory::createMuseum(vector<Coordinate> coordinates) {
    int cells = coordinates.size();
    if (useBuildingResources(150,150,150,650,cells) == false)
        return nullptr;
    Museum* m = new Museum();
    m->setCoordinates(coordinates);
    m->setProductionRate(1);
    return m;
}

Cell *LandmarkFactory::createHospital(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createTownHall(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createWaterPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createPowerPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createWastePlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createSchool(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createTrainStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createAirport(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createPoliceStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createHouse(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createApartment(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createComplex(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createHouseHold(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createForestry(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createSteelFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createConcreteFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createShop(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createOffice(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *LandmarkFactory::createMall(vector<Coordinate> coordinates)
{
    return nullptr;
}