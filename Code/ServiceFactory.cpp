#include "ServiceFactory.h"

Cell* ServiceFactory::createHospital(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	Hospital* cell = new Hospital();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell* ServiceFactory::createTownHall(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	TownHall* cell = new TownHall();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell* ServiceFactory::createWaterPlant(vector<Coordinate> coordinates) {
    return nullptr;
}

Cell* ServiceFactory::createPowerPlant(vector<Coordinate> coordinates) {
    return nullptr;
}

Cell* ServiceFactory::createWastePlant(vector<Coordinate> coordinates) {
    return nullptr;
}

Cell* ServiceFactory::createSchool(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	School* cell = new School();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell* ServiceFactory::createTrainStation(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	TrainStation* cell = new TrainStation();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell* ServiceFactory::createAirport(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	Airport* cell = new Airport();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell* ServiceFactory::createPoliceStation(vector<Coordinate> coordinates) {
    if (useBuildingResources(80,80,80,700,coordinates.size()) == false)
        return nullptr;
	PoliceStation* cell = new PoliceStation();
    cell->setCoordinates(coordinates);
    return cell;
}

Cell *ServiceFactory::createHouse(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ServiceFactory::createApartment(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ServiceFactory::createComplex(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ServiceFactory::createHouseHold(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ServiceFactory::createForestry(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ServiceFactory::createSteelFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ServiceFactory::createConcreteFactory(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ServiceFactory::createShop(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ServiceFactory::createOffice(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ServiceFactory::createMall(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ServiceFactory::createPark(vector<Coordinate> coordinates)
{
    return nullptr;
}

Cell *ServiceFactory::createMuseum(vector<Coordinate> coordinates)
{
    return nullptr;
}
