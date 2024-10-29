#include "Citizen.h"

////////////// Constructors ///////////////

/// Default Constructor
Citizen::Citizen(){
    happiness = 100;
	employment = "unemployed";
	money = 0;
    // Residence and business address can be added later, e.g., addResidence and addBusinessAdress
}

/// Variable constructor
Citizen::Citizen(int happy, Residential* acc, string job, float cash, string addr)
        : happiness(happy), accommodation(acc), employment(job), money(cash), businessAddress(addr) {}

/// Copy Constructor
Citizen::Citizen(const Citizen& other){
    happiness = other.happiness;
	employment = other.employment;
	money = other.getMoney();
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
