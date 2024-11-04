/**
* @class CommercialFactory
* @brief A class that represents a commercial factory.
* @ingroup Factory
* @implements BuildingFactory
*
* The CommercialFactory class is a concrete factory participant of the Factory design pattern. It is used to create commercial buildings.
*/
#include "CommercialFactory.h"

Cell* CommercialFactory::createShop(vector<Coordinate> coordinates) {
    if (useBuildingResources(100,100,100,800,coordinates.size()) == false)
        return nullptr;
	Shop* cell = new Shop();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell* CommercialFactory::createOffice(vector<Coordinate> coordinates) {
    if (useBuildingResources(100,100,100,800,coordinates.size()) == false)
        return nullptr;
	Office* cell = new Office();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell* CommercialFactory::createMall(vector<Coordinate> coordinates) {
    if (useBuildingResources(100,100,100,800,coordinates.size()) == false)
        return nullptr;
	Mall* cell = new Mall();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell *CommercialFactory::createHouse(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createApartment(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createComplex(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createHouseHold(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createPark(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createMuseum(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createHospital(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createTownHall(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createWaterPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createPowerPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createWastePlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createSchool(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createTrainStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createAirport(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createPoliceStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createForestry(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createSteelFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *CommercialFactory::createConcreteFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}