#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "IndustrialFactory.h"
#include "LandmarkFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "ServiceFactory.h"
#include "Block.h"
#include "Visitor.h"
#include "Section.h"
#include "Buildings.h"
#include "Hospital.h"
#include "Visitor.h"
#include "CVisitor.h"
#include "People.h"
#include "Green.h"
#include "Government.h"
#include "AddPublicTransport.h"
#include "ExpandCity.h"
#include "IncreaseTaxes.h"
#include "IncreaseWages.h"
#include "Map.h"
#include "Cell.h"
#include "Block.h"
#include "Visitor.h"
#include "Section.h"
#include "Buildings.h"
#include "Hospital.h"
#include "City.h"

TEST_CASE("City Test")
{
    Section* test = new Block();
    Section* test2 = new Block();

    Section* building1 = new Hospital();
    Section* building2 = new Park();

    test->addSection(building1);
    test2->addSection(building2);

    test->addSection(test2);

    City* newCity = new City(test);

    newCity->instanceCity();
}

// TEST_CASE("Factory method") {
//     IndustrialFactory i = IndustrialFactory();
//     Industrial* p = i.createForestry();
//     delete p;
//     p = nullptr;
//     p = i.createSteelFactory();
//     delete p;
//     p = nullptr;
//     p = i.createForestry();
//     delete p;
//     p = nullptr;
//     p = i.createConcreteFactory();
//     delete p;
//     p = nullptr;

//     LandmarkFactory l = LandmarkFactory();
//     Landmarks* park = l.createPark();
//     delete park;
//     park = nullptr;
//     park = l.createMuseum();
//     delete park;
//     park = nullptr;

//     ServiceFactory s = ServiceFactory();

//     Service* serv = s.createAirport();
//     delete serv;
//     serv = nullptr;
//     serv = s.createHospital();
//     delete serv;
//     serv = nullptr;
//     serv = s.createPoliceStation();
//     delete serv;
//     serv = nullptr;
//     serv = s.createSchool();
//     delete serv;
//     serv = nullptr;
//     serv = s.createTownHall();
//     delete serv;
//     serv = nullptr;
//     serv = s.createTrainStation();
//     delete serv;
//     serv = nullptr;

//     Utilities* utls = s.createPowerPlant();
//     delete utls;
//     utls = nullptr;
//     utls = s.createWastePlant();
//     delete utls;
//     utls = nullptr;
//     utls = s.createWaterPlant();
//     delete utls;
//     utls = nullptr;

//     ResidentialFactory r = ResidentialFactory();
//     Residential* house = r.createComplex();
//     delete house;
//     house = nullptr;
//     house = r.createApartment();
//     delete house;
//     house = nullptr;
//     house = r.createHouse();
//     delete house;
//     house = nullptr;

//     CommercialFactory f = CommercialFactory();
//     Commercial* business = f.createMall();
//     delete business;
//     business = nullptr;
//     business = f.createShop();
//     delete business;
//     business = nullptr;
//     business = f.createOffice();
//     delete business;
//     business = nullptr;
// }

// TEST_CASE("Composite") {
//     Section* test = new Block();
//     Section* test2 = new Block();

//     Section* building1 = new Hospital();
//     Section* building2 = new Park();

//     test->addSection(building1);
//     test2->addSection(building2);

//     test->addSection(test2);

//     cout << "Test: " << test << endl;
//     cout << "Building1: " << building1 << endl;
//     cout << "Test2: " << test2 << endl;
//     cout << "Building2: " << building2 << endl;
//     cout << "getSection(0): " << test->getSection(0) << endl;
//     cout << "getSection(1): " << test->getSection(1) << endl;

//     CHECK(building1 == test->getSection(0));
//     CHECK(building2 == test->getSection(1));

//     test->removeSection(1);

//     CHECK(nullptr == test->getSection(1));
// }

// TEST_CASE("Visitor")
// {
//     Section* test = new Block();
//     Section* test2 = new Block();

//     Section* building1 = new Hospital();

//     test->addSection(building1);
//     test->addSection(building1);

//     Visitor* vis = new CVisitor();

//     test->acceptVisitor(vis);

//     delete vis;
//     delete building1;
//     delete test2;
//     delete test;
// }

// TEST_CASE("State"){
//     People people(new Green());
//     Budget budget(new Green());
//     Disatisfaction dissatisfaction(new Green());

//     people.handleSeverity(true);
//     budget.handleSeverity(false);
//     dissatisfaction.handleSeverity(true);

//     people.handleSeverity(false);
//     budget.handleSeverity(true);
//     dissatisfaction.handleSeverity(false);
//     dissatisfaction.handleSeverity(false);
//     dissatisfaction.handleSeverity(false);
//     dissatisfaction.handleSeverity(true);
//     dissatisfaction.handleSeverity(true);
// }

// TEST_CASE("Government Singleton"){

//     Government newGovernment = Government::onlyInstance();
//     Government newGovernment2 = Government::onlyInstance();

// }

// TEST_CASE("City Singleton"){

//     City newCity = City::instanceCity();
//     City newCity2 = City::instanceCity();
// }

// TEST_CASE("Strategy"){
//     Government newGovernment = Government::onlyInstance();

//     People* people = new People(new Green());
//     Budget* budget = new Budget(new Green());
//     Disatisfaction* dissatisfaction = new Disatisfaction(new Green());

//     newGovernment.setPeopleState(people);
//     newGovernment.setBudgetState(budget);
//     newGovernment.setMoraleState(dissatisfaction);

//     AddPublicTransport* newStrategy = new AddPublicTransport();
//     newGovernment.setStrategy(newStrategy);
//     CHECK("AddPublicTransport" == newGovernment.implementPolicyBudget());

//     newGovernment.setBudgetState(new Budget(new Red()));
//     IncreaseTaxes* increasingTaxes = new IncreaseTaxes();
//     newGovernment.setStrategy(increasingTaxes);
//     CHECK("IncreaseTaxes" == newGovernment.implementPolicyBudget());

//     newGovernment.setMoraleState(new Disatisfaction(new Red()));

//     IncreaseWages* increasingWages = new IncreaseWages();
//     newGovernment.setStrategy(increasingWages);
//     CHECK("IncreaseWages" == newGovernment.implementPolicyMorale());

//     ExpandCity* expandingCity = new ExpandCity();

//     newGovernment.setStrategy(expandingCity);
//     cout << newGovernment.implementPolicyPeople() << endl;
//     CHECK("\033[38;5;210mNo new policy changes\033[0m" == newGovernment.implementPolicyPeople());


//     newGovernment.setPeopleState(new People(new Red()));
//     newGovernment.setStrategy(expandingCity);
//     CHECK("ExpandCity" == newGovernment.implementPolicyPeople());

//     delete newStrategy;
//     delete increasingTaxes;
//     delete increasingWages;
//     delete expandingCity;
// }

// TEST_CASE("Transport") {
//     vector<vector<Cell*>> cellMap(5, vector<Cell*>(5, nullptr));
//     vector<vector<Cell*>> matrix(5, vector<Cell*>(5, nullptr));

//     Map myMap(cellMap, matrix);
//     myMap.addNode(new Cell("Building 1"), 0, 0, 2, 2);
//     myMap.addNode(new Cell("Building 2"), 3, 3, 2, 2);

//     myMap.printMap();

// }