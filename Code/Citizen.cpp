#include "Citizen.h"


////////////// Constructors ///////////////

/// Default Constructor
Citizen::Citizen(){
    happiness = 100;
	employment = "unemployed";
	money = 0;
    pet = nullptr;
    std::cout << "A new Citizen has entered the city." << std::endl;
}

/// Variable constructor
Citizen::Citizen(int happy, Cell* acc, string job, float cash, Cell* addr, Pet* pet)
        : happiness(happy), accommodation(acc), employment(job), money(cash), businessAddress(addr), pet(pet) {
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
    money = cash;
}

//////////// Residence /////////////

/// Get residence
Cell* Citizen::getAccommodation() const{
    return accommodation;
}
/// Set residence
void Citizen::setAccommodation(Cell* acc){
    accommodation = acc;
}

//////////// Business Address /////////////

// Citizen - Get Business Address
Cell* Citizen::getBusinessAddress(){
    return businessAddress;
}

void Citizen::setBusinessAddress(Cell* address){
    businessAddress = address;
}

Citizen* Citizen::procreate() {
	return new Citizen(*this);
}