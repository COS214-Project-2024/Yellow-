#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "IndustrialFactory.h"
#include "LandmarkFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "ServiceFactory.h"
#include "UtilityFactory.h"
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
#include "Population.h"
#include "Citizen.h"
#include "Observer.h"
#include "HappyObserver.h"
#include <typeinfo>

TEST_CASE("Composite") {
    Section* test = new Block();
    Section* test2 = new Block();

    Section* building1 = new Hospital();
    Section* building2 = new Park();

    test->addSection(building1);
    test2->addSection(building2);

    test->addSection(test2);

    cout << "Test: " << test << endl;
    cout << "Building1: " << building1 << endl;
    cout << "Test2: " << test2 << endl;
    cout << "Building2: " << building2 << endl;
    cout << "getSection(0): " << test->getSection(0) << endl;
    cout << "getSection(1): " << test->getSection(1) << endl;

    CHECK(building1 == test->getSection(0));
    CHECK(building2 == test->getSection(1));

    test->removeSection(1);

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

    delete vis;
    delete building1;
    delete test2;
    delete test;
}

TEST_CASE("State"){
    People* people = new People(new Green());
    Budget* budget = new Budget(new Green());
    Disatisfaction* dissatisfaction = new Disatisfaction(new Green());

    people->handleSeverity(true);
    budget->handleSeverity(false);
    dissatisfaction->handleSeverity(true);

    people->handleSeverity(false);
    budget->handleSeverity(true);
    dissatisfaction->handleSeverity(false);
    dissatisfaction->handleSeverity(false);
    dissatisfaction->handleSeverity(false);
    dissatisfaction->handleSeverity(true);
    dissatisfaction->handleSeverity(true);
    CHECK_NOTHROW(dissatisfaction->handleSeverity(true));
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

    //AddPublicTransport

    AddPublicTransport* newStrategy = new AddPublicTransport();
    newGovernment.setStrategy(newStrategy);
    newGovernment.setBudgetState(new Budget(new Yellow()));
    newGovernment.setBudgetState(new Budget(new Green()));
    Policies * currPolicy = newGovernment.implementPolicyBudget(new Yellow());
    CHECK("AddPublicTransport" == currPolicy->getPolicy());

    //IncreaseTaxes

    IncreaseTaxes* newStrategyTaxes = new IncreaseTaxes();
    newGovernment.setStrategy(newStrategyTaxes);
    newGovernment.setBudgetState(new Budget(new Yellow()));
    newGovernment.setBudgetState(new Budget(new Red()));
    currPolicy = newGovernment.implementPolicyBudget(new Yellow());
    CHECK("IncreaseTaxes" == currPolicy->getPolicy());

    //IncreaseWages

    IncreaseWages* newStrategyWages = new IncreaseWages();
    newGovernment.setStrategy(newStrategyWages);
    newGovernment.setMoraleState(new Disatisfaction(new Yellow()));
    newGovernment.setMoraleState(new Disatisfaction(new Red()));
    currPolicy = newGovernment.implementPolicyMorale(new Yellow());
    CHECK("IncreaseWages" == currPolicy->getPolicy());

    //ExpandingCity

    ExpandCity* newStrategyCity = new ExpandCity();
    newGovernment.setStrategy(newStrategyCity);
    newGovernment.setPeopleState(new People(new Yellow()));
    newGovernment.setPeopleState(new People(new Red()));
    currPolicy = newGovernment.implementPolicyPeople(new Yellow());
    CHECK("ExpandCity" == currPolicy->getPolicy());
}

TEST_CASE("Transport") {
    vector<vector<Cell*>> cellMap(5, vector<Cell*>(5, nullptr));
    vector<vector<int>> matrix(5, vector<int>(5, 0));
    vector<Cell*> pos(5, nullptr);
    Coordinate c = Coordinate();
    vector<Coordinate> v = vector<Coordinate>();
    ServiceFactory s = ServiceFactory();
    ResidentialFactory rf = ResidentialFactory();
    Cell* hospital = s.createHospital(v);
    Cell* house = rf.createHouse(v);
    Map myMap(cellMap, matrix, pos);
    myMap.addNode(hospital, 0, 0, 2, 2);
    myMap.addNode(house, 3, 3, 2, 2);

    myMap.printMap();
}

TEST_CASE("Factory and City integration") {
    Coordinate testPosition = Coordinate(1,1);

    vector<Coordinate> testVector = vector<Coordinate>();
    testVector.push_back(testPosition);
    City city = City::instanceCity();
    int resources = 4000;
    float money = 8000;
    city.stuff.res->setConcrete(resources);
    CHECK(city.stuff.res->getConcrete() == resources);

    city.stuff.res->setSteel(resources);
    CHECK(city.stuff.res->getSteel() == resources);

    city.stuff.res->setWood(resources);
    CHECK(city.stuff.res->getWood() == resources);

    city.stuff.res->setBudget(money);
    CHECK(city.stuff.res->getBudget() == money);

    city.stuff.res->setMorale(0);
    CHECK(city.stuff.res->getMorale() == 0);

    city.stuff.res->setPopulation(10);
    CHECK(city.stuff.res->getPopulation() == 10);

    city.stuff.res->setWater(0);
    CHECK(city.stuff.res->getWater() == 0);

    city.stuff.res->setEnergy(0);
    CHECK(city.stuff.res->getEnergy() == 0);

    IndustrialFactory* industrialFactory = new IndustrialFactory();
    Industrial* cf = dynamic_cast<Industrial*>(industrialFactory->createConcreteFactory(testVector));
    CHECK(typeid(*cf) == typeid(ConcreteFactory));
    resources -= 80;
    money -= 700;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);

    Industrial* forest = dynamic_cast<Industrial*>(industrialFactory->createForestry(testVector));
    CHECK(typeid(*forest) == typeid(Forestry));
    resources -= 80;
    money -= 700;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);

    Industrial* sf = dynamic_cast<Industrial*>(industrialFactory->createSteelFactory(testVector));
    CHECK(typeid(*sf) == typeid(SteelFactory));
    resources -= 80;
    money -= 700;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);

    resources+=90;
    sf->createBuildingResource();
    cf->createBuildingResource();
    forest->createBuildingResource();
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);

    UtilityFactory utilFactory = UtilityFactory();

    Cell* power = utilFactory.createPowerPlant(testVector);
    power->createBuildingResource();
    CHECK(typeid(*power) == typeid(PowerPlant));
    resources -= 80;
    money -= 700;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);
    CHECK(city.stuff.res->getEnergy() == 150); //change value if value in code is changed

    Cell* water = utilFactory.createWaterPlant(testVector);
    CHECK(typeid(*water) == typeid(WaterPlant));
    water->createBuildingResource();
    resources -= 80;
    money -= 700;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);
    CHECK(city.stuff.res->getEnergy() == 150);

    Cell* waste = utilFactory.createWastePlant(testVector);
    CHECK(typeid(*waste) == typeid(WasteManagement));
    waste->createBuildingResource();
    resources -= 80;
    money -= 700;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);
    CHECK(city.stuff.res->getMorale() == 1);

    LandmarkFactory landmarkFactory = LandmarkFactory();
    Landmarks* park = dynamic_cast<Landmarks*>(landmarkFactory.createPark(testVector));
    CHECK(typeid(*park) == typeid(Park));
    resources -= 150;
    money -= 650;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);
    park->createBuildingResource();
    CHECK(city.stuff.res->getMorale() == 2);

    Cell* museum = landmarkFactory.createMuseum(testVector);
    CHECK(typeid(*museum) == typeid(Museum));
    resources -= 150;
    money -= 650;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);
    museum->createBuildingResource();
    CHECK(city.stuff.res->getMorale() == 3);

    ResidentialFactory houseFactory = ResidentialFactory();
    Cell* h = houseFactory.createHouseHold(testVector);
    CHECK(typeid(*h) == typeid(HouseHold));

    delete h;
    delete cf;
    cf = nullptr;
    delete sf;
    sf = nullptr;
    delete forest;
    forest = nullptr;
    delete industrialFactory;
    industrialFactory = nullptr;

    delete power;
    power = nullptr;
    delete water;
    water = nullptr;
    delete waste;
    waste = nullptr;

    delete park;
    park = nullptr;
    delete museum;
    museum = nullptr;
}

TEST_CASE("Observer") {
    Population population;
    Citizen* citizen1 = new Citizen(50, nullptr, "Teacher", 100.0f, nullptr);
    Citizen* citizen2 = new Citizen(90, nullptr, "Engineer", 200.0f, nullptr);

    population.addCitizen(citizen1);
    population.addCitizen(citizen2);
    CHECK(population.getCitizens().size() == 2);

    HappyObserver* happyObserver = new HappyObserver(population.getCitizens());
    population.attach(happyObserver);
    CHECK(population.getObservers().size() == 1);

    SUBCASE("Observer receives correct updates") {
        // Capture output for validation
        std::ostringstream oss;
        std::streambuf* coutBuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

        population.notify(); 

        std::cout.rdbuf(coutBuf);  // Restore std::cout
        std::string output = oss.str();

        CHECK(output.find("Average happiness of citizens: 70") != std::string::npos);
    }

    SUBCASE("Attach and detach observer") {
        population.detach(happyObserver);
        CHECK(population.getObservers().empty());

        // Try notifying with no observers attached (should not throw errors)
        std::ostringstream oss;
        std::streambuf* coutBuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

        population.notify();

        std::cout.rdbuf(coutBuf);  // Restore std::cout
        std::string output = oss.str();

        CHECK(output == "All observers have been notified.\n");
    }

    delete citizen1;
    delete citizen2;
    delete happyObserver;
}

TEST_CASE("Citizen and building integration") {
    
}