#ifndef CITIZEN_H
#define CITIZEN_H
#include "Residential.h"
#include "Observer.h"
#include "Pet.h"
#include <string>
using namespace std;

class Citizen{
protected:
	int happiness;						// How happy is the citizen? (Out of 100)
	string employment;					// What is the citizen's job?
	float money;						// What is the citizen's bank balance?
	Cell* accommodation;				// Where does the citizen live?					// Cell pointers
	Cell* businessAddress;				// Where does the citizen work?					// Cell pointers
	Pet* pet;							// Does the citizen have a pet?
public:
    Citizen();
    Citizen(int happy, Cell* acc, string job, float cash, Cell* addr, Pet* pet);
    Citizen(const Citizen& other);
    int getHappiness() const;
    void setHappiness(int value);
    string getEmployment() const;
    void setEmployment(string job);
    float getMoney() const;
    void setMoney(float cash);
	Cell* getAccommodation() const;
	void setAccommodation(Cell* acc);
    Cell* getBusinessAddress();
    void setBusinessAddress(Cell* address);
	Pet* getPet() const;
	void setPet(Pet* pet);
	Citizen* procreate();

};

#endif
