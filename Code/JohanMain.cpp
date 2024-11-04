#include <iostream>

#include "City.h"
#include "ServiceFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "Map.h"

using namespace std;

void makeItWork() {
    City city = City::instanceCity();

    city.stuff.res->setBudget(100000);
    city.stuff.res->setConcrete(100000);
    city.stuff.res->setSteel(100000);
    city.stuff.res->setWood(100000);
    city.stuff.res->setWage(100);
    city.stuff.res->setPropertyTaxRate(0.1);
    city.stuff.res->setBusinessTaxRate(0.2);
    city.stuff.res->setIncomeTaxRate(0.1);


    ServiceFactory s = ServiceFactory();
    ResidentialFactory r = ResidentialFactory();
    CommercialFactory c = CommercialFactory();
    Map gameMap = Map();

    Coordinate co1 = Coordinate(0, 0);
    Coordinate co2= Coordinate(4, 5);
    Coordinate co3 = Coordinate(4, 5);
    Coordinate co4 = Coordinate(4, 5);
    vector<Coordinate> v = vector<Coordinate>();
    v.push_back(co1);

    // Apartment at <0, 0>
    city.addBuilding(r.createApartment(v));
    gameMap.addNode(city.getBuildings()[0]);

    co1 = Coordinate(5, 5);
    co2 = Coordinate(5, 6);
    co3 = Coordinate(6, 5);
    co4 = Coordinate(6, 6);
    v = vector<Coordinate>();
    v.push_back(co1);
    v.push_back(co2);
    v.push_back(co3);
    v.push_back(co4);

    // Town Hall from <5, 5> to <6, 6>
    city.addBuilding(s.createTownHall(v));
    gameMap.addNode(city.getBuildings()[1]);

    co1 = Coordinate(2, 3);
    co2 = Coordinate(2, 4);
    co3 = Coordinate(3, 3);
    co4 = Coordinate(3, 4);
    v = vector<Coordinate>();
    v.push_back(co1);
    v.push_back(co2);
    v.push_back(co3);
    v.push_back(co4);

    // School from <2, 3> to <3, 4>
    city.addBuilding(s.createSchool(v));
    gameMap.addNode(city.getBuildings()[2]);

    co1 = Coordinate(2, 5);
    co2 = Coordinate(2, 6);
    co3 = Coordinate(3, 5);
    co4 = Coordinate(3, 6);
    v = vector<Coordinate>();
    v.push_back(co1);
    v.push_back(co2);
    v.push_back(co3);
    v.push_back(co4);

    // Mall from <2, 5> to <3, 6>
    city.addBuilding(c.createMall(v));
    gameMap.addNode(city.getBuildings()[3]);

    co1 = Coordinate(2, 7);
    co2 = Coordinate(2, 8);
    co3 = Coordinate(3, 7);
    co4 = Coordinate(3, 8);
    v = vector<Coordinate>();
    v.push_back(co1);
    v.push_back(co2);
    v.push_back(co3);
    v.push_back(co4);

    // Police Station from <2, 7> to <3, 8>
    city.addBuilding(s.createPoliceStation(v));
    gameMap.addNode(city.getBuildings()[4]);

    co1 = Coordinate(2, 9);
    co2 = Coordinate(2, 10);
    co3 = Coordinate(3, 9);
    co4 = Coordinate(3, 10);
    v = vector<Coordinate>();
    v.push_back(co1);
    v.push_back(co2);
    v.push_back(co3);
    v.push_back(co4);

    // Hospital from <2, 9> to <3, 10>
    city.addBuilding(s.createHospital(v));
    gameMap.addNode(city.getBuildings()[5]);

    co1 = Coordinate(0, 13);
    co2 = Coordinate(0, 14);
    co3 = Coordinate(1, 13);
    co4 = Coordinate(1, 14);
    v = vector<Coordinate>();
    v.push_back(co1);
    v.push_back(co2);
    v.push_back(co3);
    v.push_back(co4);

    // Train Station from <0, 13> to <1, 14>
    city.addBuilding(s.createTrainStation(v));
    gameMap.addNode(city.getBuildings()[6]);

    co1 = Coordinate(0, 15);
    co2 = Coordinate(0, 16);
    co3 = Coordinate(1, 15);
    co4 = Coordinate(1, 16);
    v = vector<Coordinate>();
    v.push_back(co1);
    v.push_back(co2);
    v.push_back(co3);
    v.push_back(co4);

    // Airport from <0, 15> to <1, 16>
    city.addBuilding(s.createAirport(v));
    gameMap.addNode(city.getBuildings()[7]);

    co1 = Coordinate(10, 13);
    co2 = Coordinate(10, 14);
    co3 = Coordinate(11, 13);
    co4 = Coordinate(11, 14);
    v = vector<Coordinate>();
    v.push_back(co1);
    v.push_back(co2);
    v.push_back(co3);
    v.push_back(co4);

    // Concrete Factory at <10, 13> to <11, 14>
    city.addBuilding(s.createConcreteFactory(v));
    gameMap.addNode(city.getBuildings()[8]);

    co1 = Coordinate(10, 15);
    co2 = Coordinate(10, 16);
    co3 = Coordinate(11, 15);
    co4 = Coordinate(11, 16);
    v = vector<Coordinate>();
    v.push_back(co1);
    v.push_back(co2);
    v.push_back(co3);
    v.push_back(co4);

    // Train Station at <10, 15> to <11, 16>
    city.addBuilding(s.createTrainStation(v));
    gameMap.addNode(city.getBuildings()[9]);

    co1 = Coordinate(12, 13);
    co2 = Coordinate(13, 14);
    co3 = Coordinate(12, 13);
    co4 = Coordinate(13, 14);
    v = vector<Coordinate>();
    v.push_back(co1);
    v.push_back(co2);
    v.push_back(co3);
    v.push_back(co4);

    // Steel Factory at <12, 13> to <13, 14>
    city.addBuilding(s.createSteelFactory(v));
    gameMap.addNode(city.getBuildings()[10]);

    co1 = Coordinate(12, 15);
    co2 = Coordinate(13, 16);
    co3 = Coordinate(12, 15);
    co4 = Coordinate(13, 16);
    v = vector<Coordinate>();
    v.push_back(co1);
    v.push_back(co2);
    v.push_back(co3);
    v.push_back(co4);

    // Forestry at <12, 15> to <13, 16>
    city.addBuilding(s.createForestry(v));
    gameMap.addNode(city.getBuildings()[11]);

    gameMap.printMap();
}

int main() {
    makeItWork();

    return 0;
}