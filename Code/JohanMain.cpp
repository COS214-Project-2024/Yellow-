// // #include <iostream>
// // #include <vector>
// // #include <string>
// // #include <algorithm>
// // #include <sstream>

// #include "City.h"
// #include "ServiceFactory.h"
// #include "ResidentialFactory.h"
// #include "CommercialFactory.h"
// #include "IndustrialFactory.h"
// #include "Map.h"
// #include "Cell.h"
// #include "Road.h"
// #include "RoadFactory.h"

// // using namespace std;

// // void makeItWork() {
// //     City city = City::instanceCity();

// //     city.stuff.res->setBudget(100000);
// //     city.stuff.res->setConcrete(100000);
// //     city.stuff.res->setSteel(100000);
// //     city.stuff.res->setWood(100000);
// //     city.stuff.res->setWage(100);
// //     city.stuff.res->setPropertyTaxRate(0.1);
// //     city.stuff.res->setBusinessTaxRate(0.2);
// //     city.stuff.res->setIncomeTaxRate(0.1);


//     ServiceFactory s = ServiceFactory();
//     ResidentialFactory r = ResidentialFactory();
//     CommercialFactory c = CommercialFactory();
//     IndustrialFactory i = IndustrialFactory();
//     RoadFactory road = RoadFactory();

// //     Map gameMap = Map();

// //     Coordinate co1 = Coordinate(0, 0);
// //     Coordinate co2= Coordinate(4, 5);
// //     Coordinate co3 = Coordinate(4, 5);
// //     Coordinate co4 = Coordinate(4, 5);
// //     vector<Coordinate> v = vector<Coordinate>();
// //     v.push_back(co1);

// //     // Apartment at <0, 0>
// //     // city.addBuilding(r.createApartment(v));
// //     gameMap.addNode(r.createApartment(v));

//     co1 = Coordinate(3, 2);
//     co2 = Coordinate(3, 3);
//     co3 = Coordinate(4, 2);
//     co4 = Coordinate(4, 3);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     v.push_back(co2);
//     v.push_back(co3);
//     v.push_back(co4);

//     // Town Hall from <3, 2> to <4, 3>
//     // city.addBuilding(s.createTownHall(v));
//     gameMap.addNode(s.createTownHall(v));

//     co1 = Coordinate(1, 2);
//     co2 = Coordinate(1, 3);
//     co3 = Coordinate(2, 2);
//     co4 = Coordinate(2, 3);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     v.push_back(co2);
//     v.push_back(co3);
//     v.push_back(co4);

//     // School from <1, 2> to <2, 3>
//     // city.addBuilding(s.createSchool(v));
//     gameMap.addNode(s.createSchool(v));

//     co1 = Coordinate(1, 4);
//     co2 = Coordinate(1, 5);
//     co3 = Coordinate(2, 4);
//     co4 = Coordinate(2, 5);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     v.push_back(co2);
//     v.push_back(co3);
//     v.push_back(co4);

//     // Mall from <1, 4> to <2, 5>
//     // city.addBuilding(c.createMall(v));
//     gameMap.addNode(c.createMall(v));

//     co1 = Coordinate(1, 6);
//     co2 = Coordinate(1, 7);
//     co3 = Coordinate(2, 6);
//     co4 = Coordinate(2, 7);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     v.push_back(co2);
//     v.push_back(co3);
//     v.push_back(co4);

//     // Police Station from <1, 6> to <2, 7>
//     // city.addBuilding(s.createPoliceStation(v));
//     gameMap.addNode(s.createPoliceStation(v));

//     co1 = Coordinate(1, 8);
//     co2 = Coordinate(1, 9);
//     co3 = Coordinate(2, 8);
//     co4 = Coordinate(2, 9);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     v.push_back(co2);
//     v.push_back(co3);
//     v.push_back(co4);

//     // Hospital from <1, 8> to <2, 9>
//     // city.addBuilding(s.createHospital(v));
//     gameMap.addNode(s.createHospital(v));

//     co1 = Coordinate(1, 12);
//     co2 = Coordinate(1, 13);
//     // co3 = Coordinate(1, 13);
//     // co4 = Coordinate(1, 14);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     v.push_back(co2);
//     // v.push_back(co3);
//     // v.push_back(co4);

//     // Train Station from <1, 12> to <1, 13>
//     // city.addBuilding(s.createTrainStation(v));
//     gameMap.addNode(s.createTrainStation(v));

//     co1 = Coordinate(1, 15);
//     co2 = Coordinate(1, 16);
//     // co3 = Coordinate(1, 15);
//     // co4 = Coordinate(1, 16);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     v.push_back(co2);
//     // v.push_back(co3);
//     // v.push_back(co4);

//     // Airport from <1, 15> to <1, 16>
//     // city.addBuilding(s.createAirport(v));
//     gameMap.addNode(s.createAirport(v));

//     co1 = Coordinate(7, 12);
//     co2 = Coordinate(7, 13);
//     // co3 = Coordinate(11, 13);
//     // co4 = Coordinate(11, 14);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     v.push_back(co2);
//     // v.push_back(co3);
//     // v.push_back(co4);

//     // Concrete Factory at <7, 12> to <7, 13>
//     // city.addBuilding(s.createConcreteFactory(v));
//     gameMap.addNode(i.createConcreteFactory(v));

//     co1 = Coordinate(7, 15);
//     co2 = Coordinate(7, 16);
//     // co3 = Coordinate(11, 16);
//     // co4 = Coordinate(11, 17);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     v.push_back(co2);
//     // v.push_back(co3);
//     // v.push_back(co4);

//     // Train Station at <7, 15> to <7, 16>
//     // city.addBuilding(s.createTrainStation(v));
//     gameMap.addNode(s.createTrainStation(v));

//     co1 = Coordinate(8, 12);
//     co2 = Coordinate(8, 13);
//     // co3 = Coordinate(12, 13);
//     // co4 = Coordinate(13, 14);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     v.push_back(co2);
//     // v.push_back(co3);
//     // v.push_back(co4);

//     // Steel Factory at <8, 12> to <8, 13>
//     // city.addBuilding(s.createSteelFactory(v));
//     gameMap.addNode(i.createSteelFactory(v));

//     co1 = Coordinate(8, 15);
//     co2 = Coordinate(8, 16);
//     // co3 = Coordinate(12, 16);
//     // co4 = Coordinate(13, 17);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     v.push_back(co2);
//     // v.push_back(co3);
//     // v.push_back(co4);

//     // Forestry at <8, 15> to <8, 16>
//     // city.addBuilding(s.createForestry(v));
//     gameMap.addNode(i.createForestry(v));




//     // Road From Apartment to Town Hall
//     co1 = Coordinate(0, 1);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));


//     co1 = Coordinate(1, 1);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));


//     co1 = Coordinate(2, 1);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));


//     co1 = Coordinate(3, 1);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(4, 1);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));



//     // Road from Apartment to Airport
//     co1 = Coordinate(0, 2);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 3);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 4);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 5);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 6);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 7);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 8);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 9);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 10);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 11);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 12);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 13);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(0, 14);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     // co1 = Coordinate(1, 14);
//     // v = vector<Coordinate>();
//     // v.push_back(co1);
//     // gameMap.addNode(road.createRoad(v));




//     // Road in industrial Area
//     co1 = Coordinate(7, 14);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

//     co1 = Coordinate(8, 14);
//     v = vector<Coordinate>();
//     v.push_back(co1);
//     gameMap.addNode(road.createRoad(v));

// //     // gameMap.addNode()


// //     gameMap.printMap();
// // }

// // int main() {
// //     makeItWork();

// //     return 0;
// // }