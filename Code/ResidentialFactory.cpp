#include "ResidentialFactory.h"

Residential* ResidentialFactory::createHouse() {
	return new House();
}

Residential* ResidentialFactory::createApartment() {
	return new Apartment();
}

Residential* ResidentialFactory::createComplex() {
	return new Complex();
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