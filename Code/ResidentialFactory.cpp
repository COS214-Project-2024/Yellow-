/**
* @class ResidentialFactory
* @brief A class that creates residential buildings
* @ingroup Factory
* @implements BuildingFactory
*
* The ResidentialFactory class is a concrete factory participant of the Factory design pattern. It is used to create residential buildings.
*/
#include "ResidentialFactory.h"

Residential* ResidentialFactory::createHouse() {
    if (useBuildingResources(50,50,50,500))
	    return new House();
    else 
        return nullptr;
}

Residential* ResidentialFactory::createApartment() { 
    if (useBuildingResources(50,50,50,500) == false)
        return nullptr;
    else
	    return new Apartment();
}

Residential* ResidentialFactory::createComplex() {
    if (useBuildingResources(50,50,50,500) == false)
        return nullptr;
    else
	    return new Complex();
}

Residential *ResidentialFactory::createHouseHold()
{
    if (useBuildingResources(50,50,50,500) == false)
        return nullptr;
    else
	    return new HouseHold();
}

Landmarks *ResidentialFactory::createPark()
{
    return nullptr;
}

Landmarks *ResidentialFactory::createMuseum()
{
    return nullptr;
}

Service *ResidentialFactory::createHospital()
{
    return nullptr;
}

Service *ResidentialFactory::createTownHall()
{
    return nullptr;
}

Utilities *ResidentialFactory::createWaterPlant()
{
    return nullptr;
}

Utilities *ResidentialFactory::createPowerPlant()
{
    return nullptr;
}

Utilities *ResidentialFactory::createWastePlant()
{
    return nullptr;
}

Service *ResidentialFactory::createSchool()
{
    return nullptr;
}

Service *ResidentialFactory::createTrainStation()
{
    return nullptr;
}

Service *ResidentialFactory::createAirport()
{
    return nullptr;
}

Service *ResidentialFactory::createPoliceStation()
{
    return nullptr;
}

Industrial *ResidentialFactory::createForestry()
{
    return nullptr;
}

Industrial *ResidentialFactory::createSteelFactory()
{
    return nullptr;
}

Industrial *ResidentialFactory::createConcreteFactory()
{
    return nullptr;
}

Commercial *ResidentialFactory::createShop()
{
    return nullptr;
}

Commercial *ResidentialFactory::createOffice()
{
    return nullptr;
}

Commercial *ResidentialFactory::createMall()
{
    return nullptr;
}