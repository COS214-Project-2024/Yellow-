/**
* @class UtilityFactory
* @brief Implementation of Cell factory for utility buildings
* @ingroup Factory
* @implements BuildingFactory
*
* UtilityFactory is a concrete factory participant of the Factory design pattern. It is used to create a utility building.
*/
#include "UtilityFactory.h"

Cell *UtilityFactory::createHouse(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createApartment(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createComplex(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createHouseHold(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createPark(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createMuseum(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createHospital(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createTownHall(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createWaterPlant(vector<Coordinate> coordinates)
{
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
    WaterPlant* res = new WaterPlant();
    res->setCoordinates(coordinates);
    res->setProductionRate(55);
    return res;
}

Cell *UtilityFactory::createPowerPlant(vector<Coordinate> coordinates)
{
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
    PowerPlant* res = new PowerPlant();
    res->setCoordinates(coordinates);
    res->setProductionRate(55);
    return res;
}

Cell *UtilityFactory::createWastePlant(vector<Coordinate> coordinates)
{
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
    WasteManagement* res = new WasteManagement();
    res->setCoordinates(coordinates);
    res->setProductionRate(1);
    return res;;
}

Cell *UtilityFactory::createSchool(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createTrainStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createAirport(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createPoliceStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createForestry(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createSteelFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createConcreteFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createShop(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createOffice(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *UtilityFactory::createMall(vector<Coordinate> coordinates)
{
    return nullptr;
}
