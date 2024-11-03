#include "Citizen.h"

#include "Cat.h"
#include "Dog.h"
#include "Hamster.h"
#include "Residential.h"
#include "Snake.h"
////////////// Constructors ///////////////

/// Default Constructor
Citizen::Citizen(){
    happiness = 100;
	employment = "no job";
	money = 0;
    businessAddress = nullptr;
    accommodation = nullptr;
    petChanceCalculator();
    std::cout << "A new Citizen has entered the city." << std::endl;
}

/// Variable constructor
Citizen::Citizen(int happy, Residential* acc, string job, float cash, Buildings* addr, Pet* pet)
        : happiness(happy), accommodation(acc), employment(job), money(cash), businessAddress(addr) {
    this->pet = pet;
    std::cout << "A new Citizen has entered the city." << std::endl;
}

/// Copy Constructor
Citizen::Citizen(const Citizen& other){
    happiness = other.happiness;
	employment = other.employment;
	money = other.getMoney();
    pet = other.pet;
    std::cout << "A new Citizen has entered the city." << std::endl;
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

Citizen* Citizen::procreate() {
	return new Citizen(*this);
}

void Citizen::petChanceCalculator() {
    int weGotAPet = generator.randomVal(0,100);

    if(weGotAPet < 25) {
        pet = nullptr;
        return;
    }
    if(weGotAPet < 50) {
        pet = new Dog();
        return;
    }
    if(weGotAPet < 75) {
        pet = new Cat();
        return;
    }
    if(weGotAPet < 100) {
        pet = new Hamster();
    }
}

