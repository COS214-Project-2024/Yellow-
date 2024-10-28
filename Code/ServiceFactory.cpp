#include "ServiceFactory.h"

Service* ServiceFactory::createHospital() {
	return new Hospital();
}

Service* ServiceFactory::createTownHall() {
	return new TownHall();
}

Utilities* ServiceFactory::createWaterPlant() {
	return new WaterPlant();
}

Utilities* ServiceFactory::createPowerPlant() {
	return new PowerPlant();
}

Utilities* ServiceFactory::createWastePlant() {
	return new WasteManagement();
}

Service* ServiceFactory::createSchool() {
	return new School();
}

Service* ServiceFactory::createTrainStation() {
	return new TrainStation();
}

Service* ServiceFactory::createAirport() {
	return new Airport();
}

Service* ServiceFactory::createPoliceStation() {
	return new PoliceStation();
}

Residential *ServiceFactory::createHouse()
{
    return nullptr;
}

Residential *ServiceFactory::createApartment()
{
    return nullptr;
}

Residential *ServiceFactory::createComplex()
{
    return nullptr;
}

Industrial *ServiceFactory::createForestry()
{
    return nullptr;
}

Industrial *ServiceFactory::createSteelFactory()
{
    return nullptr;
}

Industrial *ServiceFactory::createConcreteFactory()
{
    return nullptr;
}

Commercial *ServiceFactory::createShop()
{
    return nullptr;
}

Commercial *ServiceFactory::createOffice()
{
    return nullptr;
}

Commercial *ServiceFactory::createMall()
{
    return nullptr;
}

Landmarks *ServiceFactory::createPark()
{
    return nullptr;
}

Landmarks *ServiceFactory::createMuseum()
{
    return nullptr;
}
