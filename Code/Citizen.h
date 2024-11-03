#ifndef CITIZEN_H
#define CITIZEN_H
#include "Observer.h"
#include "Pet.h"
#include "RandomUtil.h"
#include <string>
class Buildings;
class Residential;
using namespace std;

class Citizen{
private:
	RandomUtil generator;
	void petChanceCalculator();
protected:
	int happiness;							// How happy is the citizen? (Out of 100)
	string employment;						// What is the citizen's job?
	float money;							// What is the citizen's bank balance?
	Residential* accommodation;				// Where does the citizen live?					// Cell pointers
	Buildings* businessAddress;				// Where does the citizen work?					// Cell pointers
	Pet* pet;								// Does the citizen have a pet?
public:
    Citizen();
    Citizen(int happy, Residential* acc, string job, float cash, Buildings* addr, Pet* pet);
    Citizen(const Citizen& other);
    int getHappiness() const;
    void setHappiness(int value);
    string getEmployment() const;
    void setEmployment(string job);
    float getMoney() const;
    void setMoney(float cash);
	Residential* getAccommodation() const;
	void setAccommodation(Residential* acc);
	Buildings* getBusinessAddress() const;
	void setBusinessAddress(Buildings* address);
	Pet* getPet() const;
	void setPet(Pet* pet);

	Citizen* procreate();

};

#endif
