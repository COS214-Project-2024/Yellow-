#include "ServiceFactory.h"

Service* ServiceFactory::createHospital(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	return new Hospital();
}

Service* ServiceFactory::createTownHall(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	return new TownHall();
}

Utilities* ServiceFactory::createWaterPlant(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	return new WaterPlant();
}

Utilities* ServiceFactory::createPowerPlant(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	return new PowerPlant();
}

Utilities* ServiceFactory::createWastePlant(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	return new WasteManagement();
}

Service* ServiceFactory::createSchool(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	return new School();
}

Service* ServiceFactory::createTrainStation(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	return new TrainStation();
}

Service* ServiceFactory::createAirport(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	return new Airport();
}

Service* ServiceFactory::createPoliceStation(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	return new PoliceStation();
}

Residential *ServiceFactory::createHouse(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *ServiceFactory::createApartment(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *ServiceFactory::createComplex(vector<Coordinate> coordinates)
{
    return nullptr;
}

Residential *ServiceFactory::createHouseHold(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *ServiceFactory::createForestry(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *ServiceFactory::createSteelFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Industrial *ServiceFactory::createConcreteFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *ServiceFactory::createShop(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *ServiceFactory::createOffice(vector<Coordinate> coordinates)
{
    return nullptr;
}

Commercial *ServiceFactory::createMall(vector<Coordinate> coordinates)
{
    return nullptr;
}

Landmarks *ServiceFactory::createPark(vector<Coordinate> coordinates)
{
    return nullptr;
}

Landmarks *ServiceFactory::createMuseum(vector<Coordinate> coordinates)
{
    return nullptr;
}
