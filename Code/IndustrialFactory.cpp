#include "IndustrialFactory.h"
Industrial* IndustrialFactory::createForestry() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
	return new Forestry();
}

Industrial* IndustrialFactory::createSteelFactory() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
	return new SteelFactory();
}

Industrial* IndustrialFactory::createConcreteFactory() {
    if (useBuildingResources(80,80,80,700) == false)
        return nullptr;
	return new ConcreteFactory();
}

Residential *IndustrialFactory::createHouse()
{
    return nullptr;
}

Residential *IndustrialFactory::createApartment()
{
    return nullptr;
}

Residential *IndustrialFactory::createComplex()
{
    return nullptr;
}

Landmarks *IndustrialFactory::createPark()
{
    return nullptr;
}

Landmarks *IndustrialFactory::createMuseum()
{
    return nullptr;
}

Service *IndustrialFactory::createHospital()
{
    return nullptr;
}

Service *IndustrialFactory::createTownHall()
{
    return nullptr;
}

Utilities *IndustrialFactory::createWaterPlant()
{
    return nullptr;
}

Utilities *IndustrialFactory::createPowerPlant()
{
    return nullptr;
}

Utilities *IndustrialFactory::createWastePlant()
{
    return nullptr;
}

Service *IndustrialFactory::createSchool()
{
    return nullptr;
}

Service *IndustrialFactory::createTrainStation()
{
    return nullptr;
}

Service *IndustrialFactory::createAirport()
{
    return nullptr;
}

Service *IndustrialFactory::createPoliceStation()
{
    return nullptr;
}

Commercial *IndustrialFactory::createShop()
{
    return nullptr;
}

Commercial *IndustrialFactory::createOffice()
{
    return nullptr;
}

Commercial *IndustrialFactory::createMall()
{
    return nullptr;
}
