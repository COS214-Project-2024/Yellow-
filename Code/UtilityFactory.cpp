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
    Cell* res = new WasteManagement();
    res->setCoordinates(coordinates);
    return res;
}

Cell *UtilityFactory::createPowerPlant(vector<Coordinate> coordinates)
{
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
    Cell* res = new PowerPlant();
    res->setCoordinates(coordinates);
    return res;
}

Cell *UtilityFactory::createWastePlant(vector<Coordinate> coordinates)
{
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
    Cell* res = new WasteManagement();
    res->setCoordinates(coordinates);
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
