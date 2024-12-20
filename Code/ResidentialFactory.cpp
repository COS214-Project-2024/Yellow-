/**
* @class ResidentialFactory
* @brief A class that creates residential buildings
* @ingroup Factory
* @implements BuildingFactory
*
* The ResidentialFactory class is a concrete factory participant of the Factory design pattern. It is used to create residential buildings.
*/
#include "ResidentialFactory.h"

Cell* ResidentialFactory::createHouse(vector<Coordinate> coordinates) {
    if (useBuildingResources(50,50,50,500,coordinates.size()) == false)
	    return nullptr;
    House* cell = new House();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell* ResidentialFactory::createApartment(vector<Coordinate> coordinates) { 
    if (useBuildingResources(50,50,50,500,coordinates.size()) == false)
        return nullptr;
    Apartment* cell = new Apartment();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell* ResidentialFactory::createComplex(vector<Coordinate> coordinates) {
    if (useBuildingResources(50,50,50,500,coordinates.size()) == false)
        return nullptr;
    Complex* cell = new Complex();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell *ResidentialFactory::createHouseHold(vector<Coordinate> coordinates)
{
    if (useBuildingResources(50,50,50,500,coordinates.size()) == false)
        return nullptr;
    HouseHold* cell = new HouseHold();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell *ResidentialFactory::createPark(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createMuseum(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createHospital(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createTownHall(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createWaterPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createPowerPlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createWastePlant(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createSchool(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createTrainStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createAirport(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createPoliceStation(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createForestry(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createSteelFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createConcreteFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createShop(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createOffice(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ResidentialFactory::createMall(vector<Coordinate> coordinates)
{
    return nullptr;
}