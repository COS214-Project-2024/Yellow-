#include "LandmarkFactory.h"

Landmarks* LandmarkFactory::createPark() {
    if (useBuildingResources(150,150,150,650))
	    return new Park();
    return nullptr;
}

Landmarks* LandmarkFactory::createMuseum() {
    if (useBuildingResources(150,150,150,650))
	    return new Museum();
    return nullptr;
}

Service *LandmarkFactory::createHospital()
{
    return nullptr;
}

Service *LandmarkFactory::createTownHall()
{
    return nullptr;
}

Utilities *LandmarkFactory::createWaterPlant()
{
    return nullptr;
}

Utilities *LandmarkFactory::createPowerPlant()
{
    return nullptr;
}

Utilities *LandmarkFactory::createWastePlant()
{
    return nullptr;
}

Service *LandmarkFactory::createSchool()
{
    return nullptr;
}

Service *LandmarkFactory::createTrainStation()
{
    return nullptr;
}

Service *LandmarkFactory::createAirport()
{
    return nullptr;
}

Service *LandmarkFactory::createPoliceStation()
{
    return nullptr;
}

Residential *LandmarkFactory::createHouse()
{
    return nullptr;
}

Residential *LandmarkFactory::createApartment()
{
    return nullptr;
}

Residential *LandmarkFactory::createComplex()
{
    return nullptr;
}

Residential *LandmarkFactory::createHouseHold()
{
    return nullptr;
}

Industrial *LandmarkFactory::createForestry()
{
    return nullptr;
}

Industrial *LandmarkFactory::createSteelFactory()
{
    return nullptr;
}

Industrial *LandmarkFactory::createConcreteFactory()
{
    return nullptr;
}

Commercial *LandmarkFactory::createShop()
{
    return nullptr;
}

Commercial *LandmarkFactory::createOffice()
{
    return nullptr;
}

Commercial *LandmarkFactory::createMall()
{
    return nullptr;
}