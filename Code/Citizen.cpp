/**
* @class Citizen
* @brief Class that represents a Citizen in the city
* @ingroup Factory
* @implements Citizen
*
* The Citizen class is a concrete factory participant of the Factory design pattern. It is used to create a Citizen in the city.
*/
#include "Citizen.h"
#include "Cat.h"
#include "Dog.h"
#include "Hamster.h"
#include "Population.h"
#include "Residential.h"

//////////////////////// Constructors ////////////////////////

/// Default Constructor
Citizen::Citizen(){
    identityNum = ++identityNumbers;
    happiness = 50;
	employment = "no job";
	money = 0;
    petChanceCalculator();
    businessAddress = nullptr;
    accommodation = nullptr;
    std::cout << "A new Citizen has entered the city." << std::endl;
}

/// Variable constructor
Citizen::Citizen(int happy, string job, float cash,  Pet* pet, Residential* acc,  Buildings* addr){
    identityNum = ++identityNumbers;

    this->happiness = happy;
    this->employment = job;
    this->money = cash;
    petChanceCalculator();
    this->accommodation = acc;
    this->businessAddress = addr;
    std::cout << "A new Citizen has entered the city." << std::endl;
}

/// Copy Constructor
Citizen::Citizen(const Citizen& other){
    identityNum = ++identityNumbers;

    this->happiness = other.happiness;
	this->employment = other.employment;
	this->money = other.getMoney();
    std::cout << "A new Citizen has entered the city." << std::endl;
}

//////////////////////// Prorotype ////////////////////////
CitizenPrototype* Citizen::procreate() {
    return new Citizen(*this);
}

////////////// Happiness ///////////////

/// Get happiness
int Citizen::getHappiness() const {
    return happiness;
}
/// Set happiness
void Citizen::setHappiness(int value) {
    happiness = value;
}

//////////// Employment /////////////

/// Get employment
string Citizen::getEmployment() const{
    return employment;
}

/// Set employment
void Citizen::setEmployment(string job){
    employment = job;
}

//////////// Money /////////////

/// Get money
float Citizen::getMoney() const{
    return money;
}

/// Set money
void Citizen::setMoney(float cash){
    if (accommodation != nullptr)
        accommodation->setMoney(accommodation->getMoney() + cash);
    if (accommodation == nullptr) {
        money = cash;
        return;
    }
}

//////////// Residence /////////////

/// Get residence
Residential* Citizen::getAccommodation() const{
    return accommodation;
}
/// Set residence
void Citizen::setAccommodation(Residential* acc){
    accommodation = acc;
}

//////////// Business Address /////////////

// Citizen - Get Business Address
Buildings* Citizen::getBusinessAddress() const{
    return businessAddress;
}

void Citizen::setBusinessAddress(Buildings* address){
    businessAddress = address;
}

void Citizen::petChanceCalculator() {
    int weGotAPet = generator.randomVal(0,100);

    if(weGotAPet < 25) {
        pet = nullptr;
        return;
    }
    if(weGotAPet < 50) {
        pet = new Dog(this);
        return;
    }
    if(weGotAPet < 75) {
        pet = new Cat(this);
        return;
    }
    if(weGotAPet < 100) {
        pet = new Hamster(this);
    }
}
