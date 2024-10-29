#include "CommercialFactory.h"

Commercial* CommercialFactory::createShop() {
    if (useBuildingResources(100,100,100,800) == false)
        return nullptr;
	return new Shop();
}

Commercial* CommercialFactory::createOffice() {
    if (useBuildingResources(100,100,100,800) == false)
        return nullptr;
	return new Office();
}

Commercial* CommercialFactory::createMall() {
    if (useBuildingResources(100,100,100,800) == false)
        return nullptr;
	return new Mall();
}

Residential *CommercialFactory::createHouse()
{
    return nullptr;
}

Residential *CommercialFactory::createApartment()
{
    return nullptr;
}

Residential *CommercialFactory::createComplex()
{
    return nullptr;
}

Landmarks *CommercialFactory::createPark()
{
    return nullptr;
}

Landmarks *CommercialFactory::createMuseum()
{
    return nullptr;
}

Service *CommercialFactory::createHospital()
{
    return nullptr;
}

Service *CommercialFactory::createTownHall()
{
    return nullptr;
}

Utilities *CommercialFactory::createWaterPlant()
{
    return nullptr;
}

Utilities *CommercialFactory::createPowerPlant()
{
    return nullptr;
}

Utilities *CommercialFactory::createWastePlant()
{
    return nullptr;
}

Service *CommercialFactory::createSchool()
{
    return nullptr;
}

Service *CommercialFactory::createTrainStation()
{
    return nullptr;
}

Service *CommercialFactory::createAirport()
{
    return nullptr;
}

Service *CommercialFactory::createPoliceStation()
{
    return nullptr;
}

Industrial *CommercialFactory::createForestry()
{
    return nullptr;
}

Industrial *CommercialFactory::createSteelFactory()
{
    return nullptr;
}

Industrial *CommercialFactory::createConcreteFactory()
{
    return nullptr;
}