/**
* @class Citizen
* @brief Class that represents a Citizen in the city
* @ingroup Factory
* @implements Citizen
*
* The Citizen class is a concrete factory participant of the Factory design pattern. It is used to create a Citizen in the city.
*/
#include "Citizen.h"

////////////// Constructors ///////////////

/// Default Constructor
Citizen::Citizen(){
    happiness = 100;
	employment = "unemployed";
	money = 0;
    std::cout << "A new Citizen has entered the city." << std::endl;
}

/// Variable constructor
Citizen::Citizen(int happy, Residential* acc, string job, float cash, string addr)
        : happiness(happy), accommodation(acc), employment(job), money(cash), businessAddress(addr) {
    std::cout << "A new Citizen has entered the city." << std::endl;
}

/// Copy Constructor
Citizen::Citizen(const Citizen& other){
    happiness = other.happiness;
	employment = other.employment;
	money = other.getMoney();
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

//////////// Residence /////////////

/// Get residence
Residential* Citizen::getAccommodation() const{
    return accommodation;
}
/// Set residence
void Citizen::setAccommodation(Residential* acc){
    accommodation = acc;
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

// Citizen - Get Business Address
string Citizen::getBusinessAddress(){
    return businessAddress;
}

void Citizen::setBusinessAddress(string address){
    businessAddress = address;
}

Citizen* Citizen::procreate() {
	return new Citizen(*this);
}