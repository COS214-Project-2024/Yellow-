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

TEST_CASE("Factory method") {
    IndustrialFactory i = IndustrialFactory();
    Industrial* p = i.createForestry();
    p = i.createSteelFactory();
    p = i.createForestry();
    p = i.createConcreteFactory();

    LandmarkFactory l = LandmarkFactory();
    Landmarks* park = l.createPark();
    park = l.createMuseum();

    ServiceFactory s = ServiceFactory();

    Service* serv = s.createAirport();
    serv = s.createHospital();
    serv = s.createPoliceStation();
    serv = s.createSchool();
    serv = s.createTownHall();
    serv = s.createTrainStation();

    Utilities* utls = s.createPowerPlant();
    utls = s.createWastePlant();
    utls = s.createWaterPlant();

    ResidentialFactory r = ResidentialFactory();
    Residential* house = r.createComplex();
    house = r.createApartment();
    house = r.createHouse();

    CommercialFactory f = CommercialFactory();
    Commercial* business = f.createMall();
    business = f.createShop();
    business = f.createOffice();
}

TEST_CASE("Composite") {
    Section* test = new Block();
    Section* test2 = new Block();

    Section* building1 = new Hospital();
    Section* building2 = new Park();

    test->addSection(building1);
    test2->addSection(building2);

    test->addSection(test2);

    test->getSection(1);

    CHECK(building1 == test->getSection(0));
    CHECK(building2 == test->getSection(1));

    test->removeSection(test2);

    CHECK(nullptr == test->getSection(1));
}

TEST_CASE("Visitor")
{
    Section* test = new Block();
    Section* test2 = new Block();

    Section* building1 = new Hospital();

    test->addSection(building1);
    test->addSection(building1);

    Visitor* vis = new CVisitor();

    test->acceptVisitor(vis);
}

TEST_CASE("State"){
    People people(new Green());
    Budget budget(new Green());
    Disatisfaction dissatisfaction(new Green());

    people.handleSeverity(true);
    budget.handleSeverity(false);
    dissatisfaction.handleSeverity(true);

    people.handleSeverity(false);
    budget.handleSeverity(true);
    dissatisfaction.handleSeverity(false);
    dissatisfaction.handleSeverity(false);
    dissatisfaction.handleSeverity(false);
    dissatisfaction.handleSeverity(true);
    dissatisfaction.handleSeverity(true);
}

TEST_CASE("Government Singleton"){

    Government newGovernment = Government::onlyInstance();
    Government newGovernment2 = Government::onlyInstance();

}

TEST_CASE("City Singleton"){

    City newCity = City::instanceCity();
    City newCity2 = City::instanceCity();
}

TEST_CASE("Strategy"){
    Government newGovernment = Government::onlyInstance();

    People* people = new People(new Green());
    Budget* budget = new Budget(new Green());
    Disatisfaction* dissatisfaction = new Disatisfaction(new Green());

    newGovernment.setPeopleState(people);
    newGovernment.setBudgetState(budget);
    newGovernment.setMoraleState(dissatisfaction);

    AddPublicTransport* newStrategy = new AddPublicTransport();
    newGovernment.setStrategy(newStrategy);
    CHECK("AddPublicTransport" == newGovernment.implementPolicyBudget());

    newGovernment.setBudgetState(new Budget(new Red()));
    IncreaseTaxes* increasingTaxes = new IncreaseTaxes();
    newGovernment.setStrategy(increasingTaxes);
    CHECK("IncreaseTaxes" == newGovernment.implementPolicyBudget());

    newGovernment.setMoraleState(new Disatisfaction(new Red()));

    IncreaseWages* increasingWages = new IncreaseWages();
    newGovernment.setStrategy(increasingWages);
    CHECK("IncreaseWages" == newGovernment.implementPolicyMorale());

    ExpandCity* expandingCity = new ExpandCity();

    newGovernment.setStrategy(expandingCity);
    cout << newGovernment.implementPolicyPeople() << endl;
    CHECK("\033[38;5;210mNo new policy changes\033[0m" == newGovernment.implementPolicyPeople());


    newGovernment.setPeopleState(new People(new Red()));
    newGovernment.setStrategy(expandingCity);
    CHECK("ExpandCity" == newGovernment.implementPolicyPeople());
}

TEST_CASE("Transport") {
    vector<vector<Cell*>> cellMap(5, vector<Cell*>(5, nullptr));
    vector<vector<Cell*>> matrix(5, vector<Cell*>(5, nullptr));

    Map myMap(cellMap, matrix);
    myMap.addNode(new Cell("Building 1"), 0, 0, 2, 2);
    myMap.addNode(new Cell("Building 2"), 3, 3, 2, 2);

    myMap.printMap();

}