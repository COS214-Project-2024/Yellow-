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

#include "SaveAndLoad.h"
#include "Saves.h"
#include "City.h"
#include "Population.h"
#include "Citizen.h"
#include "Observer.h"
#include "HappyObserver.h"
#include <typeinfo>

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
    vector<vector<Cell*>> matrix(5, vector<Cell*>(5, nullptr));

    Map myMap(cellMap, matrix);
    myMap.addNode(new Cell("Building 1"), 0, 0, 2, 2);
    myMap.addNode(new Cell("Building 2"), 3, 3, 2, 2);

    myMap.printMap();
}

TEST_CASE("Saving"){
    SaveAndLoad saveAndLoad;
    Saves saves;

    // Test saving a system state
    saveAndLoad.saveSystem(&saves);
    CHECK(saves.getSave(0) != nullptr);

    // Test loading a system state
    saveAndLoad.loadSystem(0, &saves);
    CHECK(saveAndLoad.getCurrentSystemState() != nullptr);

    // Test printing all saves
    saves.printAllSaves();

    // Test printing current save
    saveAndLoad.printCurrentSave();

    // Test invalid save number
    try
    {
        saveAndLoad.loadSystem(1, &saves);
    }
    catch (const char *msg)
    {
        CHECK(std::string(msg) == "Invalid save number");
    }

    // Test no saves available
    Saves emptySaves;
    try
    {
        emptySaves.getSave(0);
    }
    catch (const char *msg)
    {
        CHECK(std::string(msg) == "No saves available");
    }

}

TEST_CASE("Factory and City integration") {
    City city = City::instanceCity();
    int resources = 2000;
    float money = 4000;
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
    Industrial* cf = industrialFactory->createConcreteFactory();
    CHECK(typeid(*cf) == typeid(ConcreteFactory));
    resources -= 80;
    money -= 700;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);

    Industrial* forest = industrialFactory->createForestry();
    CHECK(typeid(*forest) == typeid(Forestry));
    resources -= 80;
    money -= 700;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);

    Industrial* sf = industrialFactory->createSteelFactory();
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

    ServiceFactory serviceFactory = ServiceFactory();

    Utilities* power = serviceFactory.createPowerPlant();
    power->createResource();
    CHECK(typeid(*power) == typeid(PowerPlant));
    resources -= 80;
    money -= 700;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);
    CHECK(city.stuff.res->getEnergy() == 150); //change value if value in code is changed

    Utilities* water = serviceFactory.createWaterPlant();
    CHECK(typeid(*water) == typeid(WaterPlant));
    water->createResource();
    resources -= 80;
    money -= 700;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);
    CHECK(city.stuff.res->getEnergy() == 150);

    Utilities* waste = serviceFactory.createWastePlant();
    CHECK(typeid(*waste) == typeid(WasteManagement));
    waste->createResource();
    resources -= 80;
    money -= 700;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);
    CHECK(city.stuff.res->getMorale() == 1);

    LandmarkFactory landmarkFactory = LandmarkFactory();
    Landmarks* park = landmarkFactory.createPark();
    CHECK(typeid(*park) == typeid(Park));
    resources -= 150;
    money -= 650;
    CHECK(city.stuff.res->getConcrete() == resources);
    CHECK(city.stuff.res->getSteel() == resources);
    CHECK(city.stuff.res->getWood() == resources);
    CHECK(city.stuff.res->getBudget() == money);
    park->createBuildingResource();
    CHECK(city.stuff.res->getMorale() == 2);

    Landmarks* museum = landmarkFactory.createMuseum();
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
    Residential* h = houseFactory.createHouseHold();
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
    Citizen* citizen1 = new Citizen(50, nullptr, "Teacher", 100.0f, "123 School Rd");
    Citizen* citizen2 = new Citizen(90, nullptr, "Engineer", 200.0f, "456 Tech Ave");

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