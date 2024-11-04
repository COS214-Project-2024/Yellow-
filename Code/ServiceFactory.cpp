/**
* @class ServiceFactory
* @brief A class used to create service buildings
* @ingroup Factory
* @implements ServiceFactory
*
* The ServiceFactory class is a concrete factory participant of the Factory design pattern. It is used to create service buildings.
*/
#include "ServiceFactory.h"

Service* ServiceFactory::createHospital() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
	return new Hospital();
}

Service* ServiceFactory::createTownHall() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
	return new TownHall();
}

Utilities* ServiceFactory::createWaterPlant() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
	return new WaterPlant();
}

Utilities* ServiceFactory::createPowerPlant() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
	return new PowerPlant();
}

Utilities* ServiceFactory::createWastePlant() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
	return new WasteManagement();
}

Service* ServiceFactory::createSchool() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
	return new School();
}

Service* ServiceFactory::createTrainStation() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
	return new TrainStation();
}

Service* ServiceFactory::createAirport() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
	return new Airport();
}

Service* ServiceFactory::createPoliceStation() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
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

Residential *ServiceFactory::createHouseHold()
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
